/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:07:23 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/28 21:19:14 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redir_out(char *file)
{
	int		fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		printf("Minishell: %s: Error file\n", file);
	else
	{
		dup2(fd, STDOUT_FILENO);
		close (fd);
	}
}

void	ft_append_out(char *file)
{
	int		fd;

	fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		printf("Minishell: %s: Error file\n", file);
	else
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

void	ft_redir_in(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY, 0);
	printf("fd: %d\n", fd);
	if (fd == -1)
		printf("Minishell: %s: Error file\n", file);
	else
	{
		dup2(fd, 0);
		close(fd);
	}
}

void	ft_redir_heredoc(t_redir *tmp)
{
	int	fd;

	(void)tmp;
	fd = open("/tmp/heredoc", O_RDONLY);
	if (fd == -1)
		printf("Minishell Error file\n");
	else
	{
		dup2(fd, 0);
		close (fd);
	}
}

void	ft_handle_redir(t_ast *node)
{
	t_redir	*tmp;

	tmp = node->redir_list;
	while (tmp)
	{
		if (tmp->redir_type == REDIR_OUT)
		{
			printf("out\n");
			ft_redir_out(tmp->value);
		}
		else if (tmp->redir_type == REDIR_APPEND_OUT)
		{
			printf("a out\n");
			ft_append_out(tmp->value);
		}
		else if (tmp->redir_type == REDIR_IN)
		{
			printf("in\n");
			ft_redir_in(tmp->value);
		}	
		else if (tmp->redir_type == REDIR_HEREDOC)
			ft_redir_heredoc(tmp);
		tmp = tmp->next;
	}
}
