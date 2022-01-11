/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:25:42 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/11 18:22:53 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		ft_count_pipe(t_token *list)
{
	int		count;
	t_token	*ptr;

	ptr = list;
	count = 0;
	while (ptr)
	{
		if (ptr->value[0] == '|'&& ptr->value[1] == 0)
			count++;
		ptr = ptr->next;
	}
	return (count);
}

int		ft_count_elem(t_token *list)
{
	int		count;
	t_token	*ptr;

	ptr = list;
	count = 0;
	while (list && (list->value[0] != '|' && list->value[1] != 0))
	{
		count++;
		list = list->next;
	}
	return (count);
}

t_inary	*ft_create_node(int count, nb_elem)
{
	t_inary	*node_out;

	node_out = malloc(sizeof(t_inary));
	if (node_out == NULL)
		return (NULL);
	node_out->value = calloc(SIZE, sizeof(char **));
	if (node_out->value == NULL)
	{
		free(node_out);
		return (NULL);
	}
	node_out->next = NULL;
	node_out->prev = NULL;
	return (node_out);
}

t_inary *ft_fill_tree(t_token *list, t_inary *tree)
{
	t_inary *new;
	t_inary	*holder;

	if (tree == NULL)
	{
		tree = new;
		tree->prev = NULL;
	}
	else
	{
		holder = tree;
		while (holder)
			holder = holder->next;
		new->prev = holder;
	}
	return (tree);
}

t_inary	*ft_create_tree(t_token *list)
{
	t_inary	*tree;
	int		count;
	int		nb_elem;

	nb_elem = 0;
	count = ft_count_pipe(list);
	tree = NULL;
	if (!count)
	{
		nb_elem = ft_count_elem(list);
		tree = ft_create_node(count, nb_elem);
		return (tree);
	}
	while (list)
	{
		while (count)
		{
			nb_elem = ft_count_elem(list);
			tree = ft_fill_tree(list, tree);
			count--
		}
		
	}
	return (tree);
}
