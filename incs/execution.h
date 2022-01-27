/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:15:04 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/27 12:21:55 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

void	ft_handle_pipe(t_ast *tree, t_hashtable *table);
char	*ft_exact_path(char *cmd, char **path);
int		ft_execve_cmd(t_ast *tree, t_hashtable *table);
int		ft_execute_builtin(t_ast *tree, t_hashtable *table);
int		ft_execute_builtin_before_pipe(t_ast *tree, t_hashtable *table);
int		ft_execute_builtin_in_pipe(t_ast *tree, t_hashtable *table);

#endif
