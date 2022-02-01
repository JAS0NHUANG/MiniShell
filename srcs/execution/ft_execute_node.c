/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:19:22 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/01 13:57:50 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_node(t_ast *tree, t_hashtable *table, char **envp)
{
	pid_t	pid;
	int		i;

	i = 0;
	pid = fork();
	if (pid == 0)
	{
		if (tree->redir_list)
			ft_handle_redir(tree);
		i = ft_execute_builtin(tree, &table);
		if (i != 0)
			i = ft_execve_cmd(tree, table, envp);
		g_exit_code = i;
	}
}
