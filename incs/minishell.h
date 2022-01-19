#ifndef MINISHELL_H
# define MINISHELL_H

# include "./lexer.h"
# include "./hashtable.h"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

# include <stdlib.h>

int		ft_arraylen(char **str);
t_hashtable	*ft_create_env_hashtable(char **env);

#endif
