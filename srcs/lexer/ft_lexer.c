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

static t_token	*ft_create_token(int token_len, char *input)
{
	int	i;
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
	return (new_token);
}

static int	ft_get_token_len(char *input)
{
	int	length;
	char	*ptr;

	ptr = input;
	length = 0;
	while (*ptr)
	{
		if ((ptr[0] == '<' && ptr[1] == '<') || (ptr[0] == '>' && ptr[1] == '>'))
			return (2);
		if (*ptr == '|' || *ptr == '<' || *ptr == '>')
			return (1);
		while (*ptr != '|' && *ptr != '<' && *ptr != '>' && *ptr != ' ' && *ptr)
		{
			length++;
			ptr++;
		}
		return (length);
	}
	return (0);
}

static t_token	*ft_fill_list(t_token *token_list, char *input, int token_len)
{
	t_token *holder;
	t_token	*new;

	new = ft_create_token(token_len, input);
	if (token_list == NULL)
		token_list = new; 
	else
	{
		holder = token_list;
		while (holder->next != NULL)
			holder = holder->next;
		holder->next = new;
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
