/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:06:21 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/31 13:17:08 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	res_size;
	void	*p;

	res_size = size * count;
	p = malloc(res_size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, res_size);
	return (p);
}
