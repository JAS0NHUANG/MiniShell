/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 00:18:51 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/14 14:43:16 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	char	*ptr_out;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(out = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
	ft_strlen(s2) + 1))))
		return (NULL);
	ptr_out = out;
	while (*s1)
		*ptr_out++ = *s1++;
	while (*s2)
		*ptr_out++ = *s2++;
	*ptr_out = '\0';
	return (out);
}
