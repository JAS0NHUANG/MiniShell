/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:24:20 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/28 21:51:42 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*src;

	count = 0;
	src = (unsigned char *)s;
	while (count < n)
	{
		src[count] = c;
		count++;
	}
	return (s);
}
