/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:07:15 by antton-t          #+#    #+#             */
/*   Updated: 2022/02/01 11:34:55 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *src, char *comp)
{
	int	i;

	i = 0;
	while (src[i])
	{
		while (src[i] == comp[i])
		{
			if (src[i + 1] == 0 && comp[i + 1] == 0)
				return (1);
			i++;
		}
		return (0);
	}
	return (0);
}

char	*ft_handle_null_char(char *src)
{
	char	*out;
	char	*tmp;

	out = ft_calloc(sizeof(char), 1);
	tmp = src;
	src = out;
	free(tmp);
	return (src);
}

int	ft_write_tmp_heredoc(int fd, char *tmp, char *prompt, t_token *list)
{
	if (!list->value)
		list->value = ft_handle_null_char(list->value);
	tmp = readline(prompt);
	if (!tmp)
	{
		close(fd);
		return (0);
	}
	while (ft_strcmp(list->value, tmp) != 1)
	{
		write(fd, tmp, ft_strlen(tmp));
		write(fd, "\n", 1);
		free(tmp);
		tmp = readline(prompt);
		if (!tmp)
		{
			close(fd);
			return (0);
		}
	}
	if (tmp)
		free(tmp);
	return (1);
}

void	ft_store_data(t_token *list)
{
	char	*tmp;
	char	*prompt;
	int		fd;

	prompt = "heredoc >";
	tmp = NULL;
	fd = open("/tmp/heredoc", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd == -1)
		printf("Error file opening\n");
	else
	{
		if (ft_write_tmp_heredoc(fd, tmp, prompt, list) == 0)
			return ;
	}
	close(fd);
}

void	ft_handle_heredoc(t_token *list)
{
	t_token	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->token_type == TOKEN_LESSLESSER)
		{
			ft_store_data(tmp->next);
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
	return ;
}
