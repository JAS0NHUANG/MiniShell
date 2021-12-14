/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_lexer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:31:33 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/14 17:27:42 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*ft_token_create(void)
{
	t_token	*out;

	out = malloc(sizeof(t_token));
	if (out == NULL)
		return (NULL);
	out->next = NULL;
	out->value = NULL;
	return (out);
}

int	ft_count_size(char *line)
{
	int		count;
	char	*ptr;

	ptr = line;
	count = 0;
	while (*ptr)
	{
		while (*ptr != '|' && *ptr != '<' && *ptr != '>' && *ptr != ' ' && *ptr != '\0')
		{
			count++;
			ptr++;
		}
		if (count != 0)
			return (count);
		if ((*ptr != '|' || *ptr != '<' || *ptr != '>') && *ptr)
		{
			if ((ptr[0] == '<' && ptr[1] == '<') || (ptr[0] == '>' && ptr[1] == '>'))
				return (2);
			else
				return (1);
		}
		return (0);
	}
	return (0);
}

t_token	*ft_fill_lst(t_token *out, char *line, int count)
{
	t_token *next;
	t_token	*new;

	if (out == NULL)
	{
		out = ft_copy(count, line);
		if (out == NULL)
			return (NULL);
		return (out);
	}
	else
	{
		next = out;
		while (next->next != NULL)
			next = next->next;
		new = ft_copy(count, line);
		next->next = new;
	}
	return (out);
}


t_token	*ft_start_lexer(char *line)
{
	t_token	*out;
	int		count;

	count = 0;
	out = NULL;
	while (*line)
	{
		if (*line == ' ')
		line++;
		else
		{
			count = ft_count_size(line);
			out = ft_fill_lst(out, line, count);
			while (count--)
				line++;
		}
	}
	return (out);
}
