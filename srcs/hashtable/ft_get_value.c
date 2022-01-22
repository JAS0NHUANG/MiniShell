/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:08:00 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/21 18:43:14 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "hashtable.h"

/*
**	Get the value from a key.
*/
char	*ft_get_value(t_hashtable *hashtable, char *key)
{
	int			index;
	int			key_len;
	int			table_len;
	int			hash_nbr;
	t_element	**elem_holder;

	index = 0;
	key_len = ft_strlen(key);
	table_len = hashtable->length;
	hash_nbr = ft_monkey_hash(key, hashtable->length);
	elem_holder = hashtable->element_array;
	while (elem_holder[index + hash_nbr] && \
		hash_nbr == ft_monkey_hash(elem_holder[index + hash_nbr]->key, table_len)
	)
	{
		if (ft_strncmp(elem_holder[index + hash_nbr]->key, key, key_len) == 0)
			return (elem_holder[index + hash_nbr]->value);
		index++;
	}
	return (NULL);
}
