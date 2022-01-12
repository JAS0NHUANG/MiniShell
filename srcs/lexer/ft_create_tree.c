/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:25:42 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/12 21:41:57 by antton-t         ###   ########.fr       */
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

t_inary	*ft_create_node(void)
{
	t_inary	*node_out;

	node_out = malloc(sizeof(t_inary));
	if (node_out == NULL)
		return (NULL);
	node_out->value_left = NULL;
	node_out->next = NULL;
	node_out->prev = NULL;
	return (node_out);
}

t_inary *ft_fill_tree(t_inary *tree, int nb_elem, t_token *list)
{
	t_inary *new;
	t_inary	*holder;

	new = ft_create_node();
	new = ft_fill_right_value(nb_elem, list, new);
	holder = tree;
	while (holder)
		holder = holder->next;
	holder->next = new;
	new->prev = holder;
	return (tree);
}

t_inary	*ft_create_tree(t_token *list)
{
	t_inary	*tree;
	int	nb_pipe;
	int	nb_elem;
	int	i;
	int	nb_keep;

	nb_elem = 0;
	nb_pipe = ft_count_pipe(list);
	tree = NULL;
	i = 0;
	nb_keep = nb_pipe;
/*
	if (!nb_pipe)
	{
		nb_elem = ft_count_elem(list);
		tree = ft_create_node(nb_elem, i);
		return (tree);
	}
*/
	while (list->next != NULL)
	{
		while (nb_pipe)
		{
			nb_elem = ft_count_elem(list);
			if (i == 0)
				tree = ft_create_first_node(nb_elem, list);
			else if (i == 1)
				tree = ft_fill_right_value(nb_elem, list, tree);
			else
				tree = ft_fill_tree(tree, nb_elem, list);
			while (nb_elem--)
				list = list->next;
			if (nb_pipe > 0)
				list = list->next;
			nb_pipe--;
			i++;
		}
		if (nb_keep == 1)
			tree = ft_fill_right_value(nb_elem, list, tree);
		else
			tree = ft_fill_tree(tree, nb_elem, list);
		while (list->next != NULL)
			list = list->next;
	}
	return (tree);
}
