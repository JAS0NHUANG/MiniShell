#include "minishell.h"

int	ft_env(char **argv, t_hashtable *env_ht)
{

	if (argv[1])
		return (1);
	ft_print_env(env_ht, 0);
	return (0);
}
