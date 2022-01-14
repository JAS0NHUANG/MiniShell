/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:12:38 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/14 16:09:36 by antton-t         ###   ########.fr       */
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

t_dir	*ft_create_chain(t_token *list, t_dir *chain_out, 

t_inary	*ft_create_node_list_chain(t_inary *node_out, int count, t_token *list)
{
	t_dir	*new;
	t_dir	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (count)
	{
		new = malloc(sizeof(t_dir));
		if (new == NULL)
			return (NULL);
		if (node_out->t_dir == NULL)
		{
			new->value = calloc(ft_strlen(list->value) + 1, sizeof(char));
			while (list->value[i])
			{
				new->value[i] = list->value[i];
				i++;
			}
			new->value[i] = 0;
			node_out->t_dir = new;
			new->next = NULL;
			new->prev = NULL;
			tmp = new;
		}
		else
		{
			new->value = calloc(ft_strlen(list->value) + 1, sizeof(char));
			while (list->value[i])
			{
				new->value[i] = list->value[i];
				i++;
			}
			tmp->next = new;
			new->prev = tmp;
		}
		count--;
		list = list->next;
	}
	return (node_out);
}
