/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:25:03 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/20 17:54:50 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		ft_token_dollar(char *str)
{
	int	i;

	i = 0;
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
int		ft_transform_dollar(char *str, char **env)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	while (str[i] != '$')
		i++;
	while (env[j])
	{
		l = i + 1;
		k = 0;
		if (env[j][k] == str[l])
		{
			while (env[j][k] == str[l])
			{
				if (str[l] == '?')
					return (1);
				k++;
				l++;
				if (env[j][k] == '=' && str[l] == 0)
				{
printf("MARCHE\n");
					return (1);
				}
			}
		}
		j++;
	}
printf("KO\n");
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

int		ft_check_token_prev(t_token *token_list)
{
	if (token_list->value[0] == '<')
	{
		if (token_list->value[1] == 0)
			return (1);
	}
	if (token_list->value[0] == '>')
		return (1);
	return (0);
}

char	*ft_change_dollar(char *str)
{
	char	*tmp;
	char	*tmp1;

	tmp1 = str;
	tmp = ft_strjoin(tmp1, ": ambiguous redirection\n");
	free(tmp1);
	return (tmp);
}

void	ft_parsing_dollar(t_token *token_list, char **env)
{
	while (token_list != NULL)
	{
		if (token_list->prev == NULL)
		{
			if(ft_token_dollar(token_list->value) == 1)
			{
				if (!ft_transform_dollar(token_list->value, env))
					ft_cancel_dollar(token_list->value);
			}
		}
		else
		{
			if (ft_check_token_prev(token_list->prev) == 1)
			{
				if (ft_token_dollar(token_list->value) == 1)
				{
					if (!(ft_transform_dollar(token_list->value, env) == 1))
						token_list->value = ft_change_dollar(token_list->value);
				}
			}
		}
printf("%s\n",token_list->value);
		token_list = token_list->next;
	}
}
