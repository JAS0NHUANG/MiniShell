/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_token_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:56:03 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/31 12:08:28 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expand_token_list(t_token **token_list, t_hashtable *env_ht)
{
	t_token *token_holder;
	char *value_holder;

	token_holder = *token_list;
	value_holder = NULL;
	if (!token_holder)
		return (1);
	while (token_holder)
	{
		if (token_holder->token_type == TOKEN_WORD)
		{
			value_holder = token_holder->value;
			token_holder->value = ft_expansion(token_holder->value, env_ht);
			if (value_holder)
				free(value_holder);
		}
		token_holder = token_holder->next;
	}
	return (0);
}
