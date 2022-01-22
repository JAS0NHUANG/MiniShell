/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:02:08 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/22 15:44:32 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_child(t_ast *tree, int *fd, t_hashtable *table)
{
	close(fd[0]);
	dup2(fd[1], STDIN_FILENO);
//		close(fd[1]);
	ft_execve_cmd(tree, table);
//	execlp("wc", "wc", (char *) 0);

}

void	ft_pipe_parent(t_ast *tree, int *fd, t_hashtable *table)
{
	pid_t	pid;
	close(fd[1]);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0], STDOUT_FILENO);
		ft_handle_pipe(tree->left, table);
//		close(fd[1]);
		ft_execve_cmd(tree, table);
//		execlp("ls", "ls", (char *)0);
	}
	else
		close(fd[0]);
	waitpid(-1, NULL, 0);
}

void	ft_execve_first_node(t_ast *tree, int *fd, t_hashtable *table)
{
	close(fd[0]);
	dup2(fd[1], STDIN_FILENO);
//	close(fd[1]);
	ft_execve_cmd(tree, table);
//	execlp("ls", "ls", (char *)0);
}

void	ft_handle_pipe_2(t_ast *tree, int *fd, t_hashtable *table)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		printf("FORK fail ERROR\n");
	if (pid == 0)
		ft_pipe_child(tree->right, fd, table);
	else
		ft_pipe_parent(tree, fd, table);
}

void	ft_handle_pipe(t_ast *tree, t_hashtable *table)
{
	int		fd[2];
	pid_t	stay;

	if (pipe(fd) == -1)
		printf("Error pipe creation\n");
	else
	{
		stay = fork();
		if (stay == 0)
		{
			if (tree->node_type == NODE_PIPE)
				ft_handle_pipe_2(tree, fd, table);
			else
				ft_execve_first_node(tree, fd, table);
		}
	}
	waitpid(-1, NULL, 0);
	close(fd[0]);
	close(fd[1]);
}
