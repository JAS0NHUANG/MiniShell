/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:08:57 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/28 21:11:00 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_convert_exit_code(char *str)
{
	long	nb;

	nb = ft_atoi((const char *)str);
	if (nb < 0)
		nb = 256 - (-nb % 256);
	return (nb % 256);
}

void	ft_free_content(t_ast *ast, t_hashtable *ht, t_token *token_list)
{
	if (ast)
		ft_free_ast(ast);
	if (ht)
		ft_free_hashtable(ht);
	if (token_list)
		ft_free_token_list(token_list);
}

void	ft_exit(char **str, t_ast *ast, t_hashtable *ht, t_token *token_list)
{
	int	i;

	i = 0;
	if (!str[1])
		printf("exit\n");
	else
	{
		if (ft_isdigit_str(str[1]) && str[2])
		{
			printf("exit: too many arguments\n");
			return ;
		}
		else if (!ft_isdigit_str(str[1]))
		{
			printf("exit: %s: numeric argument required\n", str[1]);
			i = 2;
		}
		else
			i = ft_convert_exit_code(str[1]);
	}
	ft_free_content(ast, ht, token_list);
	exit(i);
}
