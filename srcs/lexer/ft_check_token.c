/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:21:35 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/28 21:04:58 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_token(t_token *list)
{
	t_token	*tmp;

	tmp = list;
	if (!list)
		return (-2);
	if (list->token_type == TOKEN_PIPE)
		return (-1);
	if (list->token_type >= TOKEN_GREATER)
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
	if (list->token_type >= TOKEN_GREATER)
		return (-1);
	if (list->token_type == TOKEN_PIPE)
		return (-1);
	return (0);
}
