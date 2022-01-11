/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_ast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:23:16 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/11 18:55:20 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*ft_strcpy_ast(char *src)
{
	int		size;
	char	*out;
	int		i;

	i = 0;
	size = ft_strlen(src);
	out = (char *)malloc(sizeof(char) * (size + 1));
	if (out == NULL)
		return (NULL);
	while (src[i])
	{
		out[i] = src[i];
		i++;
	}
	out[i] = 0;
	return (out);
}
