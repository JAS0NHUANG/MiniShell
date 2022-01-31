/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:54:59 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/31 12:11:57 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_token_list(t_token *token_list)
{
	t_token	*token_list_holder;

	if (!token_list)
		return ;
	while (token_list)
	{
		free(token_list->value);
		token_list_holder = token_list;
		token_list = token_list->next;
		free(token_list_holder);
	}
	return ;
}

static int	ft_get_token_type(char *value)
{
	if ((value[0] == CHAR_LESSER && value[1] == CHAR_LESSER))
		return (TOKEN_LESSLESSER);
	if ((value[0] == CHAR_GREATER && value[1] == CHAR_GREATER))
		return (TOKEN_GREATGREATER);
	if (*value == CHAR_PIPE)
		return (TOKEN_PIPE);
	if (*value == CHAR_LESSER)
		return (TOKEN_LESSER);
	if (*value == CHAR_GREATER)
		return (TOKEN_GREATER);
	return (TOKEN_WORD);
}

static t_token	*ft_create_token(int token_len, char *input)
{
	int		i;
	t_token	*new_token;

	i = 0;
	new_token = malloc(sizeof(t_token));
	if (new_token == NULL)
		return (NULL);
	new_token->value = (char *)malloc(sizeof(char) * (token_len + 1));
	if (new_token->value == NULL)
	{
		free(new_token);
		return (NULL);
	}
	while (i < token_len)
	{
		new_token->value[i] = input[i];
		i++;
	}
	new_token->value[i] = 0;
	new_token->next = NULL;
	new_token->token_type = ft_get_token_type(new_token->value);
	return (new_token);
}

t_token	*ft_fill_list(t_token *token_list, char *input, int token_len)
{
	t_token	*holder;
	t_token	*new;

	new = ft_create_token(token_len, input);
	if (!new)
	{
		if (token_list)
			ft_free_token_list(token_list);
		return (NULL);
	}
	if (token_list == NULL)
	{
		token_list = new;
		token_list->prev = NULL;
	}
	else
	{
		holder = token_list;
		while (holder->next != NULL)
			holder = holder->next;
		holder->next = new;
		new->prev = holder;
	}
	return (token_list);
}
