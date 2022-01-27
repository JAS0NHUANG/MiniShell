/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:14:59 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/27 13:35:31 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quote(char *input)
{
	int		ret;
	char	quote_type;

	ret = 0;
	quote_type = -1;
	while (*input)
	{
		if (*input == CHAR_S_QUOTE || *input == CHAR_D_QUOTE)
		{
			quote_type = *input;
			ret = 1;
			input++;
			while (*input)
			{
				if (*input == quote_type)
				{
					ret = 0;
					break ;
				}
				input++;
			}
		}
		input++;
	}
	return (ret);
}

int	ft_check_pipe(t_token *list)
{
	t_token	*tmp;

	tmp = list;
	if (!list)
		return (-2);
	if (list->value[0] == '|')
		return (-1);
	while (list && tmp->next != NULL)
	{
		tmp = list->next;
		if ((tmp->value[0] == '<' && list->value[0] == '|')
			|| (tmp->value[0] == '>' && list->value[0] == '|'))
			return (-1);
		if (tmp->token_type >= TOKEN_PIPE && list->token_type >= TOKEN_PIPE)
			return (-1);
		list = list->next;
	}
	if (list->value[0] == '|')
		return (-1);
	return (0);
}
