/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:40:57 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/31 14:10:33 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char **av)
{
	char	*str;

	str = NULL;
	str = getcwd(str, BUFFER_SIZE);
	if (str == NULL)
	{
		ft_putstr_fd("Minishell: Error getting cwd\n", 2);
		return (EXIT_FAILURE);
	}
	if (av[1])
	{
		ft_putstr_fd("Minishell: pwd: too many arguments\n", 2);
		return (EXIT_FAILURE);
	}
	else
		printf("%s\n", str);
	free(str);
	g_exit_code = 0;
	return (EXIT_SUCCESS);
}
