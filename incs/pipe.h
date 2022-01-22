/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:15:04 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/22 15:19:06 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

void	ft_handle_pipe(t_ast *tree, t_hashtable *table);
char	*ft_exact_path(char *cmd, char **path);
int		ft_execve_cmd(t_ast *tree, t_hashtable *table);
#endif
