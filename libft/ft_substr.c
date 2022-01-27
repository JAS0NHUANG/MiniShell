/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:09:54 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/27 12:20:04 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	s_len;
	char	*result;

	index = 0;
	s_len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if ((size_t)start >= s_len)
	{
		result[0] = '\0';
		return (result);
	}
	while (s[index + start] && index < len)
	{
		result[index] = s[index + start];
		index++;
	}
	result[index] = '\0';
	return (result);
}
