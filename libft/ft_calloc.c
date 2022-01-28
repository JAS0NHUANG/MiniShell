/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:06:21 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/28 21:48:31 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	size_t	res_size;
	void	*p;

	res_size = size * count;
	if (!(p = malloc(res_size)))
		return (NULL);
	ft_memset(p, 0, res_size);
	return (p);
}
