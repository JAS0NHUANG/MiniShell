/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:58:01 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/13 18:31:10 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_doingfree(char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_doingmalloc(char **split, char const *s, char c)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		j = i;
		while (s[i] != c && s[i] != 0)
			i++;
		if (j != i)
		{
			split[count] = (char *)malloc(sizeof(char) * (i - j + 1));
			if (split[count] == NULL)
			{
				ft_doingfree(split, count);
				return (1);
			}
			split[count][i - j] = 0;
			count++;
			i--;
		}
	}
	return (0);
}

void	ft_fillstr(char **split, char const *s, char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != c && s[i] != 0)
			split[count][j++] = s[i++];
		if (j != 0)
		{
			count++;
			i--;
		}
		i++;
	}
}

int	ft_countstrings(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (s[i] != c && s[i] != 0)
		count++;
	while (s[i])
	{
		while (s[i] == c && s[i + 1] != 0)
		{
			if (s[i + 1] != c && s[i + 1] != 0)
				count++;
			i++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**split;

	if (!s)
		return (NULL);
	count = ft_countstrings(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (split == NULL)
		return (NULL);
	split[count] = NULL;
	if (ft_doingmalloc(split, s, c) == 1)
		return (NULL);
	ft_fillstr(split, s, c);
	return (split);
}
