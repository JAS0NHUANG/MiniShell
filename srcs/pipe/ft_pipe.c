/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:02:08 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/19 21:20:36 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <sys/types.h>
#include <sys/wait.h>


void	ft_pipe_child(t_inary *tree, int *fd, char **a)
{
	if (tree->type_node == NODE_PIPE)
	{
		ft_handle_pipe(tree->left);
	}
	else
	{
		close(fd[1]);
		tree->value[0] = ft_strjoin(tree->value[0], "b");
execve("/bin/ls", a, NULL);
		close(fd[0]);
	}
}

void	ft_pipe_parent(t_inary *tree, int *fd, char **a)
{
	close(fd[0]);
	tree->value[0] = ft_strjoin(tree->value[0], "a");
execve("/bin/ls", a, NULL);
	close(fd[1]);
}

void	ft_handle_pipe(t_inary *tree)
{
	pid_t	pid;
	int		fd[2];
	pid_t		count;

//t_inary	*ptr = tree;
char **a;
a = calloc(2, sizeof(char *));
a[0] = calloc(3, sizeof(char));
a[0][0] = 'l';
a[0][1] = 's';

	if (pipe(fd) == -1)
		printf("Error pipe creation\n");
	else
	{
		count = fork();
		if (count == 0)
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
					ft_pipe_child(tree->left, fd, a);
				}
				else
				{
					printf("in Parent\n");
					ft_pipe_parent(tree->right, fd, a);
				}
			}
		}
//		printf("Value final => %s\n",ptr->right->value[0]);
//execve("/bin/ls", a, NULL);
	}
	waitpid(-1, NULL, 0);
}
