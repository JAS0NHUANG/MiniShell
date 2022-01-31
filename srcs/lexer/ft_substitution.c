/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substitution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:02:03 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/31 17:14:26 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_substitute_exit_code(char **result)
{
	char	*holder;
	char	*exit_code_str;

	holder = *result;
	exit_code_str = ft_itoa(g_exit_code);
	*result = ft_strjoin(*result, exit_code_str);
	if (exit_code_str)
		free(exit_code_str);
	if (holder)
		free(holder);
}

static void	ft_free_subsitute(char *key, char *result_holder)
{
	if (key)
		free(key);
	if (result_holder)
		free(result_holder);
}

int	ft_get_key(int index, char *word, char **key)
{
	while (word[index] && word[index] != ' ' && \
		word[index] != '"' && \
		word[index] != 39 && word[index] != '$')
	{
		*key = ft_add_char(*key, word[index]);
		index++;
	}
	return (index);
}

int	ft_substitute(char **result, char *word, t_hashtable *env_ht)
{
	int		index;
	char	*key;
	char	*value;
	char	*result_holder;

	index = 1;
	key = NULL;
	value = NULL;
	if (word[index] == '?')
	{
		ft_substitute_exit_code(result);
		index++;
		return (index);
	}
	else
	{
		index = ft_get_key(index, word, &key);
		value = ft_get_value(env_ht, key);
	}
	result_holder = *result;
	*result = ft_strjoin(*result, value);
	ft_free_subsitute(key, result_holder);
	return (index);
}
