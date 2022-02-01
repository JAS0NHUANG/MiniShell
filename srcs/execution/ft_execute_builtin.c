/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:23:09 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/01 14:40:54 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit_code(t_ast *tree, t_hashtable **table)
{
	g_exit_code = ft_cd(tree->value, table);
	printf("exit cd\n");
	exit(g_exit_code);
	exit(0);
}

int	ft_execute_builtin(t_ast *tree, t_hashtable **table)
{
	char	*cmd;

	cmd = tree->value[0];
	if (!cmd || cmd[0] == '\0')
		return (1);
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		ft_exit_code(tree, table);
	else if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
	{
		ft_echo(tree->value);
		exit(0);
	}
	else if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
		exit(ft_env(tree->value, *table));
	else if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
		exit(0);
	else if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		exit(0);
	else if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
		exit(ft_pwd(tree->value));
	else if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0)
		exit(0);
	else
		return (-1);
	return (0);
}
