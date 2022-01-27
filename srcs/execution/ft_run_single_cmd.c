/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_single_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:04:16 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/27 12:54:43 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_run_single_cmd(t_ast *ast, t_hashtable **ht, t_token *token_list)
{
	char	*cmd;

	cmd = ast->value[0];
	if (ft_strncmp("exit", cmd, ft_strlen(cmd)) == 0)
		ft_exit(ast->value, ast, *ht, token_list);
	if (ft_strncmp("export", cmd, ft_strlen(cmd)) == 0)
		*ht = ft_export(ast->value, *ht);
	if (ft_strncmp("cd", cmd, ft_strlen(cmd)) == 0)
		ft_cd(ast->value, ht);
	if (ft_strncmp("unset", cmd, ft_strlen(cmd)) == 0)
		*ht = ft_unset(ast->value, *ht);
	else
		ft_handle_pipe(ast, *ht);
}
