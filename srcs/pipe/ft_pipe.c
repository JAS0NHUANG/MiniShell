/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:02:08 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/23 17:18:53 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_child(t_ast *tree, int *fd, t_hashtable *table)
{
printf("tree value child==> %s\n",tree->value[0]);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	ft_execve_cmd(tree, table);
}

void	ft_pipe_parent(t_ast *tree, int *fd, t_hashtable *table)
{
	pid_t	pid;

printf("tree value parent==> %s\n",tree->value[0]);
	close(fd[0]);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		ft_handle_pipe(tree->left, table);
		close(fd[1]);
//		exit(0);
	}
	else
		close(fd[1]);
	waitpid(-1, NULL, 0);
}

void	ft_execve_first_node(t_ast *tree, t_hashtable *table)
{
	ft_execve_cmd(tree, table);
}

void	ft_handle_pipe_2(t_ast *tree, int *fd, t_hashtable *table, pid_t stay)
{
	if (stay < 0)
		printf("FORK fail ERROR\n");
	if (stay == 0)
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
		if (tree->node_type == NODE_PIPE)
		{
			stay = fork();
			ft_handle_pipe_2(tree, fd, table, stay);
		}
		else
		{
			stay = fork();
			if (stay == 0)
				ft_execve_first_node(tree, table);
		}
	}
	waitpid(-1, NULL, 0);
	close(fd[0]);
	close(fd[1]);
}
