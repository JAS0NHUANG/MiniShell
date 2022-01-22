/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doing_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:50:19 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/22 15:31:19 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_doingmalloc(char **split, char const *s, char c)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		j = i;
		while (s[i] != c && s[i] != 0)
			i++;
		if (j != i)
		{
			split[count] = (char *)malloc(sizeof(char) * (i - j + 1));
			if (split[count] == NULL)
			{
				ft_doingfree(split, count);
				return (1);
			}
			split[count][i - j] = 0;
			count++;
			i--;
		}
	}
	return (0);
}
