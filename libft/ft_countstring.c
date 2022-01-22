/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:50:02 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/22 15:33:04 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countstrings(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (s[i] != c && s[i] != 0)
		count++;
	while (s[i])
	{
		while (s[i] == c && s[i + 1] != 0)
		{
			if (s[i + 1] != c && s[i + 1] != 0)
				count++;
			i++;
		}
		i++;
	}
	return (count);
}
