/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:02:08 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/21 21:28:42 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <sys/types.h>
#include <sys/wait.h>


void	ft_pipe_child(t_inary *tree, int *fd)
{

(void)tree;
		
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execlp("wc", "wc", (char *) 0);

}

void	ft_pipe_parent(t_inary *tree, int *fd)
{
//	pid_t	pid;

(void)tree;
	close(fd[0]);
//	pid = fork();
//	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execlp("ls", "ls", (char *)0);
	}
}

void	ft_execve_first_node(t_inary *tree, int *fd)
{
(void)tree;
	close(fd[0]);
	dup2(fd[1], STDIN_FILENO);
	close(fd[1]);
	execlp("ls", "ls", (char *)0);
}

void	ft_handle_pipe(t_inary *tree)
{
	pid_t	pid;
	int		fd[2];
	pid_t	stay;

	if (pipe(fd) == -1)
		printf("Error pipe creation\n");
	else
	{
		stay = fork();
		if (stay == 0)
		{
			if (tree->left)
			{
printf("DANS L ARBRE\n");
				pid = fork();
				if (pid < 0)
					printf("FORK fail ERROR\n");
				if (pid == 0)
				{
					printf("in Child\n");
					ft_pipe_child(tree, fd);
				}
				else
				{
					printf("in Parent\n");
					ft_pipe_parent(tree->right, fd);
				}
			}
			else
				ft_execve_first_node(tree, fd);
		}
//printf("Value final => %s\n",ptr->right->value[0]);
//execve("/bin/ls", a, NULL);
	}
	waitpid(-1, NULL, 0);
	close(fd[0]);
	close(fd[1]);
}
