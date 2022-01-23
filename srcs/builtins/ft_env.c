/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <jahuang@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 06:52:03 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/23 21:11:03 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_env(t_hashtable *env_hashtable, int is_export)
{
	int		index;
	t_element	*env_element;
	

	index = 0;
	while(index < env_hashtable->length)
	{
		if (env_hashtable->element_array[index])
		{
			env_element = env_hashtable->element_array[index];
			if (is_export)
				printf("export ");
			printf("%s=", env_element->key);
			if (is_export)
				printf("\"%s\"", env_element->value);
			else
				printf("%s", env_element->value);
			printf("\n");
		}
		index++;
	}
}

int	ft_env(char **argv, t_hashtable *env_ht)
{
	if (argv[1])
	{
		(void)env_ht;
		return (1);
	}
	(void)argv;
	ft_print_env(env_ht, 0);
	return (0);
}
