/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:14:59 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/13 18:14:36 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quote(char *input)
{
	int		ret;
	char	quote_type;

	ret = 0;
	quote_type = -1;
	while (*input)
	{
		if (*input == CHAR_S_QUOTE || *input == CHAR_D_QUOTE)
		{
			quote_type = *input;
			ret = 1;
			input++;
			while (*input)
			{
				if (*input == quote_type)
				{
					ret = 0;
					break ;
				}
				input++;
			}
		}
		input++;
	}
	return (ret);
}
