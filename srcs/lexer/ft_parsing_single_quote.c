/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_single_quote.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:31:53 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/04 17:54:24 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_parsing_single_quote(t_token *token_lst)
{
	int		enter;
	t_token	*ptr;
	int	i;

	ptr = token_lst;
	enter = 0;
	while (ptr != NULL)
	{
		i = 0;
		while (ptr->value[i] != CHAR_S_QUOTE && ptr->value[i] && enter != 1)
			i++;
		if (ptr->value[i] == CHAR_S_QUOTE && enter != 1)
		{
			enter = 1;
			i++;
		}
		while (ptr->value[i] && enter == 1)
		{
			if (ptr->value[i] == CHAR_S_QUOTE)
				enter = 0;
			i++;
		}
		ptr = ptr->next;
	}
	if (enter == 1)
		printf("Error quote not closing need to free and exit!!!\n");
}