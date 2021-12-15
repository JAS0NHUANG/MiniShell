/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:25:03 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/15 15:49:32 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		ft_token_dollar(char *str)
{
	int	i;

	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

/*
	Voir si le $PATH existe si oui retourne 1 sinon erreur
*/
int		ft_transform_dollar(char *str)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	while (str[i]!= '$')
		i++;
	while (ENV[j])
	{
		l = i;
		k = 0;
		while (ENV[j][k] == str[l])
		{
			k++;
			l++;
			if (ENV[j][k] == '=')
				return (1);
		}
		j++;
	}
	return (0);
}

void	ft_cancel_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '$')
		i++;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
}

void	ft_parsing_dollar(t_token *token_list, char **env)
{
	while (token_list != NULL)
	{
		if (token_list->prev == NULL)
		{
			if(ft_token_dollar(token_list->value) == 1)
			{
				if (!ft_transform_dollar(token_list->value))
					ft_cancel_dollar(token_list->value);
			}
		}
		else
		{
			
		}
		token_list = token_list->next;
	}
}
