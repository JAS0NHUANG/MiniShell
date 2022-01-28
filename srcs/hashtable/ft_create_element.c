/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:48:37 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/28 22:03:14 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "hashtable.h"

/*
**	Create the node(struct) to be stored in the hash table array.
*/

t_element	*ft_create_element(char *key, char *value)
{
	t_element	*new_element;

	new_element = malloc(sizeof(t_element) * 1);
	if (!new_element)
		return (NULL);
	new_element->key = ft_strdup(key);
	new_element->value = ft_strdup(value);
	free(key);
	free(value);
	return (new_element);
}
