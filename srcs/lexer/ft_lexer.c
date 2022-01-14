/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:31:33 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/13 17:54:49 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lexer(char *input)
{
	t_token	*token_list;
	int		token_len;

	token_len = 0;
	token_list = NULL;
	while (*input)
	{
		if (*input == ' ')
			input++;
		else
		{
			token_len = ft_get_token_len(input);
			token_list = ft_fill_list(token_list, input, token_len);
			input += token_len;
		}
	}
	return (token_list);
}
