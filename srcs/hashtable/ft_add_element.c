/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:22:43 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/26 17:27:17 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "minishell.h"

t_hashtable	*ft_add_element(t_hashtable *ht, char *key, char *value)
{
	int	hash_index;

	hash_index = ft_monkey_hash(key, ht->length);
	while (ht->element_array[hash_index])
	{
		if (ft_strncmp(ht->element_array[hash_index]->key, key,
				ft_strlen(key)) == 0)
		{
			ht = ft_change_value(ht, key, value, 0);
			return (ht);
		}
		hash_index = (hash_index + 1) % ht->length;
	}
	ht->element_array[hash_index] = ft_create_element(key, value);
	return (ht);
}
