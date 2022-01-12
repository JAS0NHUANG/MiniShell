/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env_hashtable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <jahuang@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:16:12 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/13 00:16:28 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_hashtable *ft_create_env_hashtable(char **env)
{
	t_hashtable	*env_hashtable;
	int		array_len;

	array_len = ft_arraylen(env);
	if (array_len == 0)
	{
		return (NULL);
	}
	array_len = ft_next_prime(array_len * 2);
	env_hashtable = ft_create_hashtable(array_len);
	printf("env hashtable addr: %p\n", env_hashtable);
	return (env_hashtable);
}
