/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:02:08 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/31 04:13:34 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_child(t_ast *tree, int *fd, t_hashtable *table)
{
	int     i;

	i = 0;
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	/*
	if (tree->redir_list)
		ft_handle_redir(tree);
	*/
	i = ft_execute_builtin(tree, &table);
	if (i != 0)
		i = ft_execve_cmd(tree, table);
	g_exit_code = i;
}

void	ft_pipe_parent(t_ast *tree, int *fd, t_hashtable *table)
{
	pid_t	pid;
	int		status;

	close(fd[0]);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		ft_handle_pipe(tree->left, table);
		close(fd[1]);
		exit(0);
	}
	else
		close(fd[1]);
	waitpid(pid, &status, 0);
}

void	ft_execute_node(t_ast *tree, t_hashtable *table)
{
	pid_t	pid;
	int i;

	i = 0;
	pid = fork();
	if (pid == 0)
	{
		i = ft_execute_builtin(tree, &table);
		if (i != 0)
			i = ft_execve_cmd(tree, table);
		g_exit_code = i;
	}
}

void	ft_handle_pipe_2(t_ast *tree, int *fd, t_hashtable *table)
{
	pid_t	stay;

	stay = fork();
	if (stay < 0)
		write(2, "Minishell: Error: Failed creating fork.\n", 40);
	if (stay == 0)
		ft_pipe_child(tree->right, fd, table);
	else
		ft_pipe_parent(tree, fd, table);
}

void	ft_handle_pipe(t_ast *tree, t_hashtable *table)
{
	int		status;
	int		fd[2];

	if (pipe(fd) == -1)
		write(2, "Minishell: Error: Failed creating pipe.\n", 40);
	else
	{
		if (tree->node_type == NODE_PIPE)
			ft_handle_pipe_2(tree, fd, table);
		else
			ft_execute_node(tree, table);
	}
	waitpid(-1, &status, 0);
	g_exit_code = WEXITSTATUS(status);
	close(fd[0]);
	close(fd[1]);
}
