/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:48:37 by jahuang           #+#    #+#             */
/*   Updated: 2021/12/09 11:05:43 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	return (new_element);
}
