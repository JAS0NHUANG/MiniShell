/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:11:15 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/22 00:35:24 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./hashtable.h"
# include "./lexer.h"
# include "./parser.h"
# include "../libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

t_hashtable	*ft_create_env_hashtable(char **env);
void		ft_print_env(t_hashtable *env_hashtable, int is_export);
t_hashtable	*ft_export(char **argv, t_hashtable *hashtable);
int		ft_env(char **argv, t_hashtable *hashtable);
t_hashtable	*ft_unset(char **argv, t_hashtable *hashtable);

#endif
