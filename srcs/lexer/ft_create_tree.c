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

t_inary	*ft_create_node(int nb_elem)
{
	t_inary	*node_out;

	node_out = malloc(sizeof(t_inary));
	if (node_out == NULL)
		return (NULL);
	node_out->value_right = calloc(nb_elem + 1, sizeof(char **));
	node_out->next = NULL;
	node_out->prev = NULL;
	return (node_out);
}

t_inary	*ft_create_first_node(int nb_elem, t_token *list)
{
	t_inary	*node_out;
	t_token	*ptr;
	int	i;

	i = 0;
	ptr = list;
	node_out = malloc(sizeof(t_inary));
	if (node_out == NULL)
		return (NULL);
	node_out->value_left = calloc(nb_elem + 1, sizeof(char **));
	while (ptr->value[0] == '|' && ptr->value[1] == 0)
	{
		node_out->value_left[i] = ft_strcpy_ast(ptr->value);
		ptr = ptr->next;
		i++;
	}
	node_out->next = NULL;
	node_out->prev = NULL;
	return (node_out);
}

t_inary *ft_fill_tree(t_inary *tree)
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

t_inary *ft_fill_fist_right_value(int nb_elem, t_token *list, t_inary *tree)
{
	t_token	*ptr;
	int	i;

	i = 0;
	ptr = list;
	tree->value_right = calloc(nb_elem + 1, sizeof(char **));
		while (ptr->value[0] == '|' && ptr->value[1] == 0)
	{
		node_out->value_right[i] = ft_strcpy_ast(ptr->value);
		ptr = ptr->next;
		i++;
	}
	return (tree);
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

t_inary *ft_fill_fist_right_value(int nb_elem, t_token *list, t_inary *tree)
{
	t_token	*ptr;

	ptr = list;
	tree->value_right = calloc(nb_elem + 1, sizeof(char **));
	
		node_out->value_left[i] = ft_strcpy_ast(ptr->value);
		ptr = ptr->next;
}

t_inary	*ft_create_tree(t_token *list)
{
	t_inary	*tree;
	int	nb_pipe;
	int	nb_elem;
	int	i;

	nb_elem = 0;
	nb_pipe = ft_count_pipe(list);
	tree = NULL;
	i = 0;
/*
	if (!nb_pipe)
	{
		nb_elem = ft_count_elem(list);
		tree = ft_create_node(nb_elem, i);
		return (tree);
	}
*/
	while (list)
	{
		nb_elem = ft_count_elem(list);
		if (i == 0)
			tree = ft_create_fist_node(nb_elem, list);
		if (i == 1)
			tree = ft_fill_first_right_value(nb_elem, list, tree);
		else
			tree = ft_create_node(nb_elem);
		while (nb_elem--)
			list = list->next;
		while (nb_elem--)
			list = list->next;
	}
	return (tree);
}
