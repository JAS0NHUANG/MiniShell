/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <jahuang@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 06:53:16 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/31 14:12:44 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_error(char *argument)
{
	ft_putstr_fd("MiniShell: unset: ", 2);
	ft_putstr_fd(argument, 2);
	ft_putstr_fd(": \'not a valid identifier\'\n", 2);
	return ;
}

int	ft_is_valid(char *str)
{
	while (*str)
	{
		if (!ft_isalpha((int)*str) && \
				!ft_isdigit((int)*str) && \
				*str != '_')
			return (0);
		str++;
	}
	return (1);
}

t_hashtable	*ft_unset(char **argv, t_hashtable *env_ht)
{
	while (*argv && *argv[0])
	{
		if ((!ft_isalpha((int)*argv[0]) && *argv[0] != '_') || \
				(!ft_is_valid(*argv)))
		{
			g_exit_code = 1;
			ft_print_error(*argv);
			return (env_ht);
		}
		else
			env_ht = ft_delete_element(env_ht, *argv);
		argv++;
	}
	g_exit_code = 0;
	return (env_ht);
}
