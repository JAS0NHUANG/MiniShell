/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:52:32 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/20 11:06:24 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_array(char **str_array)
{
	int	index;

	index = 0;
	while (str_array[index])
	{
		ft_putstr_fd(str_array[index], 1);
		ft_putstr_fd(" ", 1);
		index++;
	}
	ft_putstr_fd("\n", 1);
}
