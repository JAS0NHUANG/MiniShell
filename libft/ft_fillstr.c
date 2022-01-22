/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:50:27 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/22 15:33:39 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fillstr(char **split, char const *s, char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != c && s[i] != 0)
			split[count][j++] = s[i++];
		if (j != 0)
		{
			count++;
			i--;
		}
		i++;
	}
}
