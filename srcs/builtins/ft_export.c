/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <jahuang@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 06:51:48 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/31 17:14:50 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_error(char *argv_index)
{
	ft_putstr_fd("MiniShell: export: \'", 2);
	ft_putstr_fd(argv_index, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
	return ;
}

int	ft_export_type(char *str)
{
	if (!ft_isalpha((int)str[0]) && str[0] != '_')
		return (0);
	while (*str)
	{
		if (*str == '=')
			return (1);
		if (str[0] == '+' && str[1] == '=')
			return (2);
		if (!ft_isalpha((int)*str) && \
			!ft_isdigit((int)*str) && \
			*str != '_')
			return (0);
		str++;
	}
	return (1);
}

char	**ft_get_key_value(char *argument, int export_type)
{
	char		**key_value;
	int			char_index;

	key_value = malloc(2 * sizeof(char *));
	if (!key_value)
		return (NULL);
	char_index = ft_index_of(argument, '=');
	if (export_type == 2)
		char_index--;
	if (char_index < 0)
	{
		key_value[0] = ft_strdup(argument);
		key_value[1] = ft_strdup("");
	}
	else
	{
		key_value[0] = ft_substr(argument, 0, char_index);
		char_index++;
		if (export_type == 2)
			char_index++;
		key_value[1] = ft_substr(argument, char_index,
				ft_strlen(argument) - char_index);
	}
	return (key_value);
}

t_hashtable	*ft_do_export(char **argv, t_hashtable *env_ht)
{
	int		index;
	int		export_type;
	char	**key_value;

	index = 1;
	while (argv[index])
	{
		export_type = ft_export_type(argv[index]);
		if (export_type == 0)
		{
			g_exit_code = 1;
			ft_print_error(argv[index]);
		}
		key_value = ft_get_key_value(argv[index], export_type);
		if (export_type == 1)
			env_ht = ft_add_element(env_ht, key_value[0], key_value[1]);
		if (export_type == 2)
			env_ht = ft_ch_value(env_ht, key_value[0], key_value[1], 1);
		free(key_value[0]);
		free(key_value[1]);
		free(key_value);
		index++;
	}
	return (env_ht);
}

t_hashtable	*ft_export(char **argv, t_hashtable *env_ht)
{
	if (!argv[1])
	{
		ft_print_env(env_ht, 1);
		g_exit_code = 0;
		return (env_ht);
	}
	env_ht = ft_do_export(argv, env_ht);
	g_exit_code = 0;
	return (env_ht);
}
