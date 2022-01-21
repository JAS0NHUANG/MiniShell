/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:11:15 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/21 14:00:23 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./hashtable.h"
# include "./builtins.h"
# include "./lexer.h"
# include "./parser.h"
# include "../libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <readline/history.h>

t_hashtable	*ft_create_env_hashtable(char **env);

#endif
