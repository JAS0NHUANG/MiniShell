/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <jahuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:04:18 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/26 16:48:01 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_free_result(size_t word_index, char **result)
{
	size_t	index;

	index = 0;
	while (index < word_index)
	{
		free(result[index]);
		index++;
	}
	free(result);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	word_count;
	size_t	index;
	size_t	s_len;

	word_count = 0;
	index = 0;
	s_len = ft_strlen(s);
	while (index < s_len)
	{
		if (s[index] != c)
		{
			word_count++;
			while (s[index] != c && index < s_len)
				index++;
		}
		index++;
	}
	return (word_count);
}

static size_t	ft_word_len(const char *s, char c, size_t index)
{
	size_t	length;
	size_t	s_len;

	s_len = ft_strlen(s);
	length = 0;
	while (index < s_len && s[index] != c)
	{
		length++;
		index++;
	}
	return (length);
}

static void	ft_writer(char **result, char *s, char c)
{
	size_t	index;
	size_t	word_len;
	size_t	word_index;

	index = 0;
	word_index = 0;
	while (index < ft_strlen(s))
	{
		if (s[index] != c)
		{
			word_len = ft_word_len(s, c, index);
			result[word_index] = ft_substr(s, (unsigned int)index, word_len);
			if (!result[word_index])
			{
				ft_free_result(word_index, result);
				return ;
			}
			index += word_len;
			word_index++;
		}
		index++;
	}
	result[word_index] = (0);
}

char	**ft_split(const char *s, char c)
{
	size_t	word_count;
	char	**result;

	word_count = ft_count_words(s, c);
	result = (char **)malloc(((int)word_count + 1) * sizeof(char *));
	if (!result)
		return (0);
	ft_writer(result, (char *)s, c);
	return (result);
}
