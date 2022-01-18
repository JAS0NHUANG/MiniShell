/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:23:00 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/18 21:36:53 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *cmd, char *cmd_tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (cmd_tab[i])
	{
		k = 0;
		j = 0;
		if (cmd_tab[i][k] == cmd[j])
		{
			while (cmd_tab[i][k] == cmd[j])
			{
				if (cmd[j + 1] = 0)
					return (i);
				k++;
				j++;
			}
		}
		i++;
	}
	return (-1);
}

char	*ft_strcpy(char dest, char src)
{
	int	i;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	**ft_build_builtins(char **cmd)
{
	cmd[0] = calloc(5, sizeof(char));
	cmd[0] = ft_strcpy(cmd[0], "echo");
	cmd[1] = calloc(3, sizeof(char));
	cmd[0] = ft_strcpy(cmd[0], "cd");
	cmd[1] = calloc(4, sizeof(char));
	cmd[0] = ft_strcpy(cmd[0], "pwd");
	cmd[1] = calloc(7, sizeof(char));
	cmd[0] = ft_strcpy(cmd[0], "export");
	cmd[1] = calloc(6, sizeof(char));
	cmd[0] = ft_strcpy(cmd[0], "unset");
	cmd[1] = calloc(4, sizeof(char));
	cmd[0] = ft_strcpy(cmd[0], "env");
	cmd[1] = calloc(5, sizeof(char));
	cmd[0] = ft_strcpy(cmd[0], "exit");
	return(cmd);
}

int	ft_execve(char *str)
{
	char **builtins;

	builtins = calloc(8, sizeof(char **));
	builtins = ft_build_builtins(builtins);
	return (ft_strcmp_builtins(str, builtins);
}
