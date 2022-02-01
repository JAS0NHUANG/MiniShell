/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:15:04 by antton-t          #+#    #+#             */
/*   Updated: 2022/02/01 12:58:45 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

void	ft_handle_pipe(t_ast *tree, t_hashtable *table, char **envp);
void	ft_execute_node(t_ast *tree, t_hashtable *table, char **envp);
void	ft_run_single_cmd(t_ast *ast, t_hashtable **ht, t_token *token_list,
			char **envp);
char	*ft_exact_path(char *cmd, char **path);
int		ft_execve_cmd(t_ast *tree, t_hashtable *table, char **envp);
int		ft_execute_builtin(t_ast *tree, t_hashtable **table);

#endif
