/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:32:54 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/27 12:26:48 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_char_array(char **char_array)
{
	int	index;

	index = 0;
	while (char_array[index])
	{
		free(char_array[index]);
		index++;
	}
	if (char_array)
		free(char_array);
	return ;
}
