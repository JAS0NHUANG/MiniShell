/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:09:57 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/31 18:15:56 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo_n(char *src)
{
	int	i;

	if (!src)
		return (0);
	i = 0;
	if (src[i] == '-')
	{
		i++;
		if (src[i] != 'n')
			return (0);
		while (src[i] == 'n')
			i++;
	}
	if (src[i] == 0)
		return (1);
	return (0);
}

void	ft_echo(char **src)
{
	int	i;
	int	n;
	int	count;

	n = 0;
	i = 1;
	if (ft_echo_n(src[i]))
	{
		n = 1;
		i++;
	}
	count = i;
	while (src[count])
		count++;
	while (src[i])
	{
		ft_putstr_fd(src[i], 1);
		i++;
		if (i != count)
			ft_putstr_fd(" ", 1);
	}
	if (n == 0)
		ft_putstr_fd("\n", 1);
	g_exit_code = 0;
}
