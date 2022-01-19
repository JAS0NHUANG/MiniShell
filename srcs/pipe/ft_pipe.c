/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:02:08 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/19 12:20:53 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		ft_count_pipe_tree(t_inary *tree)
{
	int	count;

	count = 0;
	while (tree)
	{
		if (tree->type_node == NODE_PIPE)
			count++;
		tree = tree->left;
	}
	return (count);
}

void	ft_handle_pipe(t_inary *tree)
{
	t_inary	*ptr;
	int		nb_pipe;
	pid_t	pid;

	nb_pipe = ft_count_pipe_tree(tree);
	while (nb_pipe)
	{
		ptr = tree;
		pid_t = fork;
		if (pid_t < 0)
		{
			printf("FORK fail ERROR\n");
		}
		if (pid_t == 0)
		{
			printf("in Child\n");
		}
		else
		{
			printf("in Parent\n");
		}
		nb_pipe--;
	}
}
