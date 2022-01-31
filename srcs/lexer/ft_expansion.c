/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <jahuang@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 06:59:43 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/31 10:06:53 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_add_char(char *str, char c)
{
	int	index;
	char	*result;
	int	str_len;

	if (!c)
		return (str);
	str_len = 0;
	if (str)
		str_len = ft_strlen(str);
	result = ft_calloc(sizeof(char), str_len + 2);
	if (!result)
		return (NULL);
	index = 0;
	while (str && str[index])
	{
		result[index] = str[index];
		index++;
	}
	result[index] = c;
	result[index + 1] = '\0';
	if (str)
		free(str);
	return (result);
}

void	ft_substitute_exit_code(char **result)
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

int	ft_substitute(char **result, char *word, t_hashtable *env_ht)
{
	int	index;
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
		while (word[index] && word[index] != ' ' && \
			word[index] != '"' && \
			word[index] != 39 && word[index] != '$')
		{
			key = ft_add_char(key, word[index]);
			index++;
		}
		value = ft_get_value(env_ht, key);
	}
	result_holder = *result;
	*result = ft_strjoin(*result, value);
	if (key)
		free(key);
	if (result_holder)
		free(result_holder);
	return (index);
}

int	ft_single_quote(char **result, char *word, int index)
{
	char 	*holder;
	char	*result_holder;
	int	in_quote_len;

	holder = NULL;
	result_holder = NULL;
	in_quote_len = -1;
	in_quote_len = ft_index_of((word + index + 1), (char)39);
	if (in_quote_len != -1)
	{
		holder = ft_substr(word, index + 1, in_quote_len);
		result_holder = *result;
		*result = ft_strjoin(*result, holder);
		if (holder)
			free(holder);
		if (result_holder)
			free(result_holder);
		index = index + in_quote_len + 2;
	}
	else
	{
		*result = ft_add_char(*result, word[index]);
		index++;
	}
	return (index);
}

int	ft_double_quote(char **result, char *word, int index, t_hashtable *env_ht)
{
	int	in_quote_len;

	in_quote_len = ft_index_of((word + index + 1), '"');
	if (in_quote_len != -1)
	{
		index++;
		while (word[index] && word[index] != '"')
		{
			if (word[index] == '$')
				index  += ft_substitute(result, &word[index], env_ht);
			else
			{
				*result = ft_add_char(*result, word[index]);
				index++;
			}
		}
		index++;
	}
	else
	{
		*result = ft_add_char(*result, word[index]);
		index++;
	}
	return (index);
}

char *ft_expansion(char *word, t_hashtable *env_ht)
{
	int	index;
	char	*result;

	index = 0;
	result = NULL;
	while (word[index])
	{
		if (word[index] == 39)
		{
			index = ft_single_quote(&result, word, index);
		}
		else if (word[index] == '"')
			index = ft_double_quote(&result, word, index, env_ht);
		else if (word[index] == '$')
			index  += ft_substitute(&result, &word[index], env_ht);
		else
		{
			result = ft_add_char(result, word[index]);
			index++;
		}
	}
	return (result);
}
