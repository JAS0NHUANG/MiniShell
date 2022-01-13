/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:54:28 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/13 17:56:45 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_length_in_quote(char *ptr)
{
	int	length;
	int	quote_type;

	quote_type = -1;
	length = 1;
	if (*ptr == CHAR_S_QUOTE)
		quote_type = CHAR_S_QUOTE;
	else
		quote_type = CHAR_D_QUOTE;
	ptr++;
	while (*ptr)
	{
		length++;
		if (*ptr == quote_type)
			return (length);
		ptr++;
	}
	return (length);
}

int	ft_get_token_len(char *input)
{
	int		length;
	int		to_add;

	length = 0;
	to_add = 1;
	if ((input[0] == '<' && input[1] == '<') || \
		(input[0] == '>' && input[1] == '>'))
		length = 2;
	else if (*input == '|' || *input == '<' || *input == '>')
		length = 1;
	else
	{
		while (*input && *input != '|' && *input != '<' && \
			*input != '>' && *input != ' ')
		{
			if (*input == CHAR_S_QUOTE || *input == CHAR_D_QUOTE)
				to_add = ft_length_in_quote(input);
			length += to_add;
			input += to_add;
		}
	}
	return (length);
}
