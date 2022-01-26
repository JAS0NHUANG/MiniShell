/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:47:13 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/26 16:47:15 by antton-t         ###   ########.fr       */
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
