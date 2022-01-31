/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:15:31 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/31 14:02:40 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "minishell.h"

t_hashtable	*ft_add_element(t_hashtable *ht, char *key, char *value)
{
	int	hash;

	hash = ft_monkey_hash(key, ht->length);
	while (ht->element_array[hash])
	{
		if (ft_strncmp(ht->element_array[hash]->key, key, ft_strlen(key)) == 0)
		{
			ht = ft_ch_value(ht, key, value, 0);
			return (ht);
		}
		hash = (hash + 1) % ht->length;
	}
	ht->element_array[hash] = ft_create_element(key, value);
	return (ht);
}
