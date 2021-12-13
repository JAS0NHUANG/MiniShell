/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_lexer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:31:33 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/13 20:12:50 by antton-t         ###   ########.fr       */
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

int	ft_count_size(char *src, int i)
{
	int	size;

	size = 0;
	while (src[i] == ' ' && src[i])
		i++;
	while (src[i] != '|' && src[i] != '<' && src[i] != '>' && src[i] != ' '
		&& src[i])
	{
		i++;
		size++;
	}
	if (size > 0)
		return (size);
	if (src[i] == '|' || src[i] == '<' || src[i] == '>')
	{
		if ((src[i] == '<' && src[i + 1] == '<' ) || (src[i] == '>'
				&& src[i] == '>'))
			return (2);
		else
			return (1);
	}
	return (size);
}

t_token	*ft_fill_chain_lst(char *str, int i, int count)
{
	t_token	*out;
	int		j;

	j = 0;
	out = ft_token_create();
	out->value = (char *)malloc(sizeof(char) * (count + 1));
	if (out->value == NULL)
		return (NULL);
	while (j < count)
	{
		out->value[j] = str[i];
		j++;
		i++;
	}
	out->value[j] = 0;
	return (out);
}

t_token	*ft_fill_lst(t_token *out, char *src, int i, int count)
{
	t_token	*ptr;
	int		j;
	t_token	*new;

	j = 0;
	ptr = out;
	while (ptr->next != NULL)
		ptr = ptr->next;
	new = ft_token_create();
	if (new == NULL)
		return (NULL);
	new->value = (char *)malloc(sizeof(char) * (count + 1));
	if (new->value == NULL)
		return (NULL);
	ptr->next = new;
	while (j < count)
	{
		new->value[j] = src[i];
		j++;
		i++;
	}
	new->value[j] = 0;
	return (out);
}

t_token	*ft_start_lexer(char *line)
{
	t_token	*out;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		count = ft_count_size(line, i);
		if (i == 0)
			out = ft_fill_chain_lst(line, i, count);
		else
			out = ft_fill_lst(out, line, i, count);
		i = i + count;
	}
	return (out);
}
