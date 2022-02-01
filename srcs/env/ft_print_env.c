/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:30:42 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/01 12:56:58 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_printer(char *value)
{
	ft_putstr_fd("\"", 1);
	ft_putstr_fd(value, 1);
	ft_putstr_fd("\"", 1);
}

void	ft_print_env(t_hashtable *env_hashtable, int is_export)
{
	int			index;
	t_element	*env_element;

	index = 0;
	if (!env_hashtable)
		return ;
	while (index < env_hashtable->length)
	{
		if (env_hashtable->element_array[index])
		{
			env_element = env_hashtable->element_array[index];
			if (is_export)
				ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(env_element->key, 1);
			ft_putstr_fd("=", 1);
			if (is_export)
				ft_export_printer(env_element->value);
			else
				ft_putstr_fd(env_element->value, 1);
			printf("\n");
		}
		index++;
	}
}
