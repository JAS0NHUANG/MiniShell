/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:11:15 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/23 06:55:49 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./hashtable.h"
# include "./lexer.h"
# include "./parser.h"
# include "./builtins.h"
# include "../libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

t_hashtable	*ft_create_env_hashtable(char **env);
void		ft_print_env(t_hashtable *env_hashtable, int is_export);

#endif
