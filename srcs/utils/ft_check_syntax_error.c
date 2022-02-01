/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:26:50 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/31 17:27:33 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_syntax_error(t_token *input)
{
	int	i;

	i = 0;
	i = ft_check_token(input);
	if (i == -1)
	{
		printf("Syntaxe Err0r: Minion Shell\n");
		return (1);
	}
	else if (i == -2)
		return (1);
	return (0);
}
