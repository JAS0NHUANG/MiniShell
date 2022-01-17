/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:19:45 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/17 18:11:34 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		ft_count_elem(t_token *list)
{
	int		count;
	t_token	*ptr;

	ptr = list;
	count = 0;
	while (ptr && ptr->token_type != TOKEN_PIPE)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

int		ft_count_pipe(t_token *list)
{
	t_token	*ptr;
	int		count;

	count = 0;
	ptr = list;

	while (ptr)
	{
		if (ptr && ptr->token_type == TOKEN_PIPE)
				count++;
		ptr = ptr->next;
	}
	return (count);
}


t_inary	*ft_malloc_node(int nb_elem)
{
	t_inary	*node_out;

	node_out = malloc(sizeof(t_inary));
	if (node_out == NULL)
		return (NULL);
	node_out->t_dir = NULL;
	node_out->left = NULL;
	node_out->right = NULL;
	node_out->value = calloc(nb_elem + 1 , sizeof(char **));
	return (node_out);
}

t_inary	*ft_create_node(t_token *list, t_inary *tree, int nb_elem)
{
	t_token	*ptr;
	t_inary	*new_node;
	int		i;

	i = 0;
	ptr = list;
	new_node = ft_malloc_node(nb_elem);
	if (ptr->token_type == TOKEN_PIPE)
	{
		(void)list;
		new_node->value[0] = calloc(2, sizeof(char));
		new_node->value[0][0] = '|';
		new_node->type_node = NODE_PIPE;
		new_node->left = tree;
		return (new_node);
	}
	else
	{
		if (ft_check_list_dir(nb_elem, list) == 1)
		{
			new_node->type_node = NODE_CMD;
			while (nb_elem--)
			{
				new_node->value[i] = ft_strcpy_ast(ptr->value);
				i++;
				ptr = ptr->next;
			}
			if (tree == NULL)
				return (new_node);
			else
				tree->right = new_node;
		}
		else
		{
			new_node->type_node = NODE_LIST;
			if (tree == NULL)
				return (ft_create_node_list_chain(new_node, nb_elem, list));
			else
				tree->right = ft_create_node_list_chain(new_node, nb_elem, list);
		}
	}
	return (tree);
}

t_inary	*ft_create_tree(t_token *list)
{
	t_inary	*tree;
	int		nb_elem;
	int		nb_pipe;

	tree = NULL;
	nb_pipe = ft_count_pipe(list);
	while (nb_pipe)
	{
		nb_elem = ft_count_elem(list);
		if (nb_elem == 0)
			return (NULL);
		tree = ft_create_node(list, tree, nb_elem);
		while (nb_elem)
		{
			list = list->next;
			nb_elem--;
		}
		if (list->token_type == TOKEN_PIPE)
		{
			tree = ft_create_node(list, tree, 1);
			list = list->next;
			nb_pipe--;
		}
	}
	if (list != NULL)
	{
		nb_elem = ft_count_elem(list);
		tree = ft_create_node(list, tree, nb_elem);
	}
	return (tree);
}
