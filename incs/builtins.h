/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:03:26 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/24 15:24:03 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "./hashtable.h" 
# define BUFFER_SIZE 3000

void		ft_echo(char **src);
void		ft_exit(char **src);
int			ft_pwd(void);
int			ft_cd(char **str, t_hashtable *env_table);
void		ft_exit(char **str);
//int			ft_env(char **argv, t_hashtable *env_ht)
//t_hashtable	*ft_export(char **argv, t_hashtable *env_ht)
//t_hashtable	*ft_unset(char **argv, t_hashtable *env_ht)

#endif
