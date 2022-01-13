/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:12:38 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/13 19:31:31 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_check_list_dir(int nb_elem, t_token *list)
{
	while (nb_elem)
	{
		if (list->token_type == TOKEN_GREATER || list->token_type == TOKEN_GREATGREATER || list->token_type == TOKEN_LESSER || list->token_type == TOKEN_LESSLESSER)
			return(0);
		nb_elem--;
		list = list->next;
	}
	return (1);
}
