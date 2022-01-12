/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:33:17 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/12 21:41:58 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_inary *ft_fill_right_value(int nb_elem, t_token *list, t_inary *tree)
{
	t_token	*ptr;
	int	i;

	i = 0;
	ptr = list;
	tree->value_right = calloc(nb_elem + 1, sizeof(char **));
printf("TEST %s\n",ptr->value);
//ERRRRRRRRRRRRRRRORRRRRRRRRRR il ne prend pas le dernier element
	while ((ptr->value[0] != '|' && ptr->value[1] != 0) && ptr->next != NULL)
	{
		tree->value_right[i] = ft_strcpy_ast(ptr->value);
printf("Test Node right[%i] => %s\n", i, tree->value_right[i]);
		ptr = ptr->next;
		i++;
	}
	return (tree);
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
	while (ptr->value[0] != '|' && ptr->value[1] != 0)
	{
		node_out->value_left[i] = ft_strcpy_ast(ptr->value);
printf("Test Node left[%i] => %s\n", i, node_out->value_left[i]);
		ptr = ptr->next;
		i++;
	}
	node_out->next = NULL;
	node_out->prev = NULL;
	return (node_out);
}
