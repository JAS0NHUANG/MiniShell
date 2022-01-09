/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:39:40 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/09 18:52:49 by antton-t         ###   ########.fr       */
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

t_inary	*ft_fill_tree(t_inaray *tree, t_token *token_list)
{
	t_inary	*holder;
	t_inary	*new;


}

t_inary	*ft_create_tree(t_token *token_list)
{
	t_inary	*tree;
	int		count;

	tree = NULL;
	count = ft_count_pipe(token_list);
	if (count == 0)
		return (NULL);
	while (token_list)
	{
		tree = ft_fill_tree(tree, token_list);
		token_list = token_list->next;
	}
}
