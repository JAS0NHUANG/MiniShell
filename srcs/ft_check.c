/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:00:20 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/17 21:19:06 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_check_pipe(t_inary * tree)
{
	t_inary	*ptr;

	while (tree->left != NULL)
	{
		ptr = tree;
		ptr = ptr->right;
printf("Left value => %s Right value => %s\n",tree->value[0], ptr->value[0]);
		if (ptr->value == NULL && ptr->t_dir == NULL)
		{
			printf("Minishell Error\n");
			return (0);
		}
		tree = tree->left;
	}
	return (1);
}

int	ft_check_input_pipe_end(char *src)
{
	int	i;

	i = 0;
	if (src[0] == '|')
		return (-1);
	while (src[i])
		i++;
	i--;
	while (src[i] == ' ')
		i--;
	if (src[i] == '|')
		return (0);
	return (1);
}

int	ft_check_input(t_token *list)
{
	t_token	*ptr;

	ptr = list;
	while (list && ptr->next != NULL)
	{
		ptr = list;
		ptr = ptr->next;
		if (list->token_type >= 2 && ptr->token_type >= 2)
		{
printf("ERROR dans l input printf fct check input ft_check\n");
			return (1);
		}
		list = list->next;
	}
	return (0);
}
