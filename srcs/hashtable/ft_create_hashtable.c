/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_hashtable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:47:54 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/30 03:35:30 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

/*
**	Create and initialize the hash table.
*/

t_hashtable	*ft_create_hashtable(int length)
{
	int			index;
	t_hashtable	*new_hashtable;

	index = 0;
	new_hashtable = (t_hashtable *)malloc(sizeof(t_hashtable) * 1);
	if (!new_hashtable)
		return (NULL);
	new_hashtable->length = length;
	new_hashtable->element_array = malloc(sizeof(t_element) * length);
	if (!new_hashtable->element_array)
	{
		free(new_hashtable);
		return (NULL);
	}
	while (index < length)
	{
		new_hashtable->element_array[index] = NULL;
		index++;
	}
	return (new_hashtable);
}
