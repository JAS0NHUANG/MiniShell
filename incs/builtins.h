/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:03:26 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/31 14:10:43 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define BUFFER_SIZE 3000

void		ft_echo(char **src);
int			ft_pwd(char **av);
int			ft_cd(char **str, t_hashtable **env_table);
void		ft_exit(char **str, t_ast *ast, t_hashtable *ht, t_token *tokens);
int			ft_env(char **argv, t_hashtable *hashtable);
t_hashtable	*ft_export(char **argv, t_hashtable *hashtable);
t_hashtable	*ft_unset(char **argv, t_hashtable *hashtable);

#endif
