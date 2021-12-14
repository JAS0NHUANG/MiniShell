/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:44:49 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/14 17:26:31 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*ft_copy(int count, char *line)
{
	int	i;
	t_token	*out;

	i = 0;
	out = ft_token_create();
	if (out == NULL)
		return (NULL);
	out->value = (char *)malloc(sizeof(char) * (count + 1));
	if (out->value == NULL)
		return (NULL);
	while (i < count)
	{
		out->value[i] = line[i];
		i++;
	}
	out->value[i] = 0;
	return (out);
}
