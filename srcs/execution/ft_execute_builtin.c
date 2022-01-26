/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:23:42 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/26 17:28:15 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute_builtin(t_ast *tree, t_hashtable *table)
{
	if (ft_strncmp(tree->value[0], "cd", 3) == 0)
		(ft_cd(tree->value, &table));
	else if (ft_strncmp(tree->value[0], "echo", 5) == 0)
		ft_echo(tree->value);
	else if (ft_strncmp(tree->value[0], "env", 4) == 0)
		(ft_env(tree->value, table));
	else if (ft_strncmp(tree->value[0], "export", 7) == 0)
		return (0);
	else if (ft_strncmp(tree->value[0], "exit", 5) == 0)
		exit (0);
	else if (ft_strncmp(tree->value[0], "pwd", 4) == 0)
		ft_pwd();
	else if (ft_strncmp(tree->value[0], "unset", 6) == 0)
		table = ft_unset(tree->value, table);
	else
		return (-1);
	return (0);
}
