/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:02:08 by antton-t          #+#    #+#             */
/*   Updated: 2022/02/01 04:16:52 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_handle_signal(int sg)
{
	if (sg == 2)
	{
		write(1, "\n", 2);
		g_exit_code = 130;
		return ;
	}
	if (sg == 3)
	{
		write(0, "     quit \n", 11);
		g_exit_code = 131;
		return ;
	}
	return ;
}

void	ft_pipe_child(t_ast *tree, int *fd, t_hashtable *ht, char** envp)
{
	int	i;

	i = 0;
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	if (tree->redir_list)
		ft_handle_redir(tree);
	i = ft_execute_builtin(tree, &ht);
	if (i != 0)
		i = ft_execve_cmd(tree, ht, envp);
	g_exit_code = i;
}

void	ft_pipe_parent(t_ast *tree, int *fd, t_hashtable *ht, char **envp)
{
	pid_t	pid;
	int		status;

	close(fd[0]);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		ft_handle_pipe(tree->left, ht, envp);
		close(fd[1]);
		exit(0);
	}
	else
		close(fd[1]);
	waitpid(pid, &status, 0);
}

void	ft_handle_pipe_2(t_ast *tree, int *fd, t_hashtable *ht, char **envp)
{
	pid_t	stay;

	stay = fork();
	if (stay < 0)
		write(2, "Minishell: Error: Failed creating fork.\n", 40);
	if (stay == 0)
		ft_pipe_child(tree->right, fd, ht, envp);
	else
		ft_pipe_parent(tree, fd, ht, envp);
}

void	ft_handle_pipe(t_ast *tree, t_hashtable *ht, char **envp)
{
	int		status;
	int		fd[2];

	signal(SIGINT, &ft_handle_signal);
	signal(SIGQUIT, &ft_handle_signal);
	if (pipe(fd) == -1)
		write(2, "Minishell: Error: Failed creating pipe.\n", 40);
	else
	{
		if (tree->node_type == NODE_PIPE)
			ft_handle_pipe_2(tree, fd, ht, envp);
		else
			ft_execute_node(tree, ht, envp);
	}
	waitpid(-1, &status, 0);
	if (WIFEXITED(status))
		g_exit_code = WEXITSTATUS(status);
	close(fd[0]);
	close(fd[1]);
}
