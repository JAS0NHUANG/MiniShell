/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:02:08 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/21 22:56:30 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <sys/types.h>
#include <sys/wait.h>


void	ft_pipe_child(t_inary *tree, int *fd)
{

	(void)tree;

	close(fd[0]);
	dup2(fd[1], STDIN_FILENO);
//		close(fd[1]);
	execlp("wc", "wc", (char *) 0);

}

void	ft_pipe_parent(t_inary *tree, int *fd)
{
	pid_t	pid;
	close(fd[1]);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0], STDOUT_FILENO);
		ft_handle_pipe(tree->left);
//		close(fd[1]);
		execlp("ls", "ls", (char *)0);
	}
	else
		close(fd[0]);
	waitpid(-1, NULL, 0);
}

void	ft_execve_first_node(t_inary *tree, int *fd)
{
	(void)tree;
	close(fd[0]);
	dup2(fd[1], STDIN_FILENO);
//	close(fd[1]);
	execlp("ls", "ls", (char *)0);
}

void	ft_handle_pipe_2(t_inary *tree, int *fd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		printf("FORK fail ERROR\n");
	if (pid == 0)
		ft_pipe_child(tree->right, fd);
	else
		ft_pipe_parent(tree, fd);
}

void	ft_handle_pipe(t_inary *tree)
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
			if (tree->value == NULL)
				ft_handle_pipe_2(tree, fd);
			else
				ft_execve_first_node(tree, fd);
		}
	}
	waitpid(-1, NULL, 0);
	close(fd[0]);
	close(fd[1]);
}
