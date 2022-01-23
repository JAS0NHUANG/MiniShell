/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:52:05 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/23 20:39:31 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_token_list(t_token *token_list)
{
	t_token	*ptr;

	ptr = token_list;
	while (token_list && ptr->next != NULL)
	{
		ptr = token_list;
		ptr = ptr->next;
		if (token_list->token_type >= 2 && ptr->token_type >= 2)
		{
			printf("syntax error near unexpected token\n");
			return (0);
		}
		if (token_list->token_type == TOKEN_PIPE && ptr->token_type == TOKEN_PIPE)
		{
			printf("syntax error near unexpected token `|'\n");
			return (0);
		}
		token_list = token_list->next;
	}
	return (1);
}
