/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_single_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:04:16 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/01 04:19:48 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_run_single_cmd(t_ast *ast, t_hashtable **ht, t_token *list, 
		char **envp)
{
	char	*cmd;

	cmd = ast->value[0];
	if (ft_strncmp("exit", cmd, ft_strlen(cmd)) == 0)
		ft_exit(ast->value, ast, *ht, list);
	else if (ft_strncmp("export", cmd, ft_strlen(cmd)) == 0)
		*ht = ft_export(ast->value, *ht);
	else if (ft_strncmp("cd", cmd, ft_strlen(cmd)) == 0)
		g_exit_code = ft_cd(ast->value, ht);
	else if (ft_strncmp("unset", cmd, ft_strlen(cmd)) == 0)
		*ht = ft_unset(ast->value, *ht);
	else
		ft_handle_pipe(ast, *ht, envp);
}
