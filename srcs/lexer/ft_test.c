/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:39:40 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/11 14:24:20 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_count_pipe(t_token *lst)
{
	int	count;
	t_token	*ptr;

	ptr = lst;
	count = 0;
	while (ptr != NULL)
	{
		if (ptr->value[0] == '|' && ptr->value[1] == 0)
			count++;
		ptr = ptr->next;
	}
	return (count);
}

t_inary	*ft_fill_value_tree(t_token *token_list, int count)
{
	t_inary	*new;

	new = malloc(sizeof(t_inary));
	if (new == NULL)
		return (NULL);
	new->value = calloc((ft_strlen(token_list->value) + 1), sizeof(char));
	if (new->value == NULL)
	{
		free(new);
		return (NULL);
	}
	while (count)
	{
		if (new->value[0] == 0)
			strcpy(new->value, token_list->value);
		else
		{
			new->value = ft_strjoin(new->value, " ");
			new->value = ft_strjoin(new->value, token_list->value);
		}
		token_list = token_list->next;
		count--;
	}
	return (new);
}

t_inary	*ft_fill_tree(t_inary *tree, t_token *token_list, int count)
{
	t_inary	*holder;
	t_inary	*new;

	new = NULL;
	if (tree == NULL)
	{
		tree = ft_fill_value_tree(token_list, count);
		tree->left = NULL;
		tree->right = NULL;
		return (tree);
	}
	else
	{
		holder = tree;
		while(holder)
			holder = holder->right;
		new = ft_fill_value_tree(token_list, count);
		new->left = holder;
	}
	return (tree);
}

t_inary	*ft_create_tree_test(t_token *token_list)
{
	t_inary	*tree;
	int		count;
	t_token	*ptr;
	int	i;

	tree = NULL;
	i = ft_count_pipe(token_list);
printf("COUNT %i \n",i);
	if (i == 0)
		return (NULL);
	while (token_list && i)
	{
		count = 0;
		ptr = token_list;
		while ((token_list->value[0] != '|' && token_list->value[1] != 0) && token_list->next != NULL)
		{
			count++;
			token_list = token_list->next;
			i--;
		}
		tree = ft_fill_tree(tree, ptr, count);
		token_list = token_list->next;
	}
	return (tree);
}
