/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:02:08 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/17 16:50:05 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_handle_pipe(t_inary *tree)
{
	t_inary	*ptr;

	while (tree)
	{
		ptr= tree;
		ptr = ptr->right;
printf("TREE LEFT ==>  %s  \n",tree->value[0]);
if (ptr->type_node == NODE_LIST)
printf("TREE RIGHT==>  %s  \n",ptr->t_dir->value);
else
printf("TREE RIGHT==>  %s  \n",ptr->value[1]);
		tree = tree->left;
	}
}
