/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_of.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <jahuang@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 04:27:11 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/28 15:16:36 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_index_of(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (-1);
}
