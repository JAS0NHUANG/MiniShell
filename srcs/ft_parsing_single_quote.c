/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_single_quote.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:31:53 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/27 18:22:34 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_parsing_single_quote(t_token *token_lst)
{
	int		enter;
	t_token	*ptr;
	
	ptr = token_lst;
	enter = 0;
	while (ptr != NULL)
	{
		if (ptr->value[i] == ''')
		{
			enter = 1;
			i++;
		}
		ptr = ptr->next;
	}
}
