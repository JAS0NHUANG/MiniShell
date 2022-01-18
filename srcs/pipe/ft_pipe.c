/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:02:08 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:58:13 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_handle_pipe(t_inary *tree)
{
	t_inary	*ptr;
	int		nb_pipe;

	ptr = tree;
	while (tree && ptr)
	{
		ptr = tree;
		ptr = ptr->right;
printf("TREE middle ==>  %s  \n",tree->value[0]);
/*
if (ptr->type_node == NODE_LIST)
printf("TREE RIGHT==>  %s  \n",ptr->t_dir->value);
else
*/
printf("TREE RIGHT==>  %s  \n",ptr->value[0]);
		tree = tree->left;
	}
}
