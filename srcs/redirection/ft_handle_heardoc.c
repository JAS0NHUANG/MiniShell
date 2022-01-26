/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_heardoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:07:15 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/26 13:35:59 by antton-t         ###   ########.fr       */
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

void	ft_store_data(t_token *list)
{
	char	*tmp;
	char	*prompt;

	prompt = "heredoc >";
	tmp = NULL;
	list->fd = open("./tmp/tmp", O_CREAT | O_RDWR | O_APPEND, 0777);
	if (list->fd == -1)
		printf("Error file opening\n");
	else
	{
		tmp = readline(prompt);
		while (ft_strcmp(list->value, tmp) != 1)
		{
			write(list->fd, tmp, ft_strlen(tmp));
			write(list->fd, "\n", 1);
			tmp = readline(prompt);
		}
	}
	close(list->fd);
}

void	ft_handle_heardoc(t_token *list)
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
