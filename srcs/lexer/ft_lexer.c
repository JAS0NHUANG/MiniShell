/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:31:33 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/13 00:06:52 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static int	ft_length_in_quote(char *ptr)
{
	int length;
	int quote_type;

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

static int	ft_get_token_len(char *input)
{
	int		length;
	int		to_add;

	length = 0;
	to_add = 1;
	if ((input[0] == '<' && input[1] == '<') || (input[0] == '>' && input[1] == '>'))
		length = 2;
	else if (*input == '|' || *input == '<' || *input == '>')
		length = 1;
	else 
	{
		while (*input && *input != '|' && *input != '<' && *input != '>' && *input != ' ')
		{
			if (*input == CHAR_S_QUOTE || *input == CHAR_D_QUOTE)
				to_add = ft_length_in_quote(input);
			length += to_add;
			input += to_add;
		}
	}
	return (length);
}

static t_token	*ft_fill_list(t_token *token_list, char *input, int token_len)
{
	t_token	*holder;
	t_token	*new;

	new = ft_create_token(token_len, input);
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

t_token	*ft_lexer(char *input)
{
	t_token	*token_list;
	int	token_len;

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
