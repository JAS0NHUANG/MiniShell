/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:12:38 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/17 16:59:45 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_check_list_dir(int nb_elem, t_token *list)
{
	while (nb_elem)
	{
		if (list->token_type == TOKEN_GREATER || list->token_type == TOKEN_GREATGREATER || list->token_type == TOKEN_LESSER || list->token_type == TOKEN_LESSLESSER)
			return(0);
		nb_elem--;
		list = list->next;
	}
	return (1);
}

t_dir	*ft_create_chain(t_token *list, t_dir *chain_out)
{
	int	i;

	i = 0;
	chain_out->value = calloc(ft_strlen(list->value) + 1, sizeof(char));
	while (list->value[i])
	{
		chain_out->value[i] = list->value[i];
		i++;
	}
	if (list->token_type == TOKEN_GREATER)
		chain_out->list_value = LIST_GREATER;
	else if (list->token_type == TOKEN_GREATGREATER)
		chain_out->list_value = LIST_GREATGREATER;
	else if (list->token_type == TOKEN_LESSER)
		chain_out->list_value = LIST_LESSER;
	else if (list->token_type == TOKEN_LESSLESSER)
		chain_out->list_value = LIST_LESSLESSER;
	return (chain_out);
}

t_inary	*ft_create_node_list_chain(t_inary *node_out, int count, t_token *list)
{
	t_dir	*new;
	t_dir	*tmp;

	tmp = NULL;
	while (count)
	{
		new = malloc(sizeof(t_dir));
		if (new == NULL)
			return (NULL);
		if (node_out->t_dir == NULL)
		{
			new = ft_create_chain(list, new);
			node_out->t_dir = new;
			new->next = NULL;
			new->prev = NULL;
			new->list_value = LIST_CMD;
			tmp = new;
		}
		else
		{
			new = ft_create_chain(list, new);
			if (tmp->list_value == LIST_GREATER || tmp->list_value == LIST_GREATGREATER || tmp->list_value == LIST_LESSER || tmp->list_value == LIST_LESSLESSER)
				new->list_value = LIST_FILE;
			else
				new->list_value = LIST_CMD;
			tmp->next = new;
			new->prev = tmp;
			tmp = new;
		}
		count--;
		list = list->next;
	}
	return (node_out);
}
