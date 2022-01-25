/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:08:57 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/25 09:56:21 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit_check(char **str)
{
	int	i;
	int	letter;

	i = 0;
	letter = 0;
	while (str[1][i])
	{
		if (str[1][i] <= 0 && str[1][i] >= 9)
			letter = 1;
		if (letter == 1)
			return (2);
		i++;
	}
	return (1);
}

int	ft_exit_check_1(char **str)
{
	long	nb;

////////////// ATOI///////////////

	nb = atoi(str[1]);
	if ( nb >= 0 && nb <= 255)
		return (nb);
	if (nb < 0)
		nb = -nb;
	return (nb % 256);
}

void	ft_exit(char **str)
{
	int	i;

	if (str[1] == 0)
	{
		/// FREE;
		printf("exit\n");
		exit(0);
	}
	else if (str[2] != 0)
	{
		if (ft_exit_check(str) == 1)
			printf("exit: too many arguments\n");
		else
		{
			/// FREE;
			printf("exit: %s: numeric argument required\n", str[1]);
			exit(2);
		}
	}
	else
	{
		i = ft_exit_check_1(str);
		printf("exit\n");
		exit(i);
	}
}
