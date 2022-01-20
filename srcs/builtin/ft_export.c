#include "minishell.h"

void	ft_puterror(char **argv, char *err_message)
{
	ft_putstr_fd("MiniShell: ", 2);
	ft_putstr_fd("not a valid identifier\n", 2);
}

int	ft_check_validity(char *str)
{

}

int	ft_modify_env(char **argv, t_hashtable *env_hashtable)
{
	int index;

	index = 0;
	while (argv[index])
	{
		if (ft_check_validity(argv[index]) == 0)
		{
		}
		else if (append)
		else



	}
	return (1);
}

t_hashtable	*ft_export(char **argv, t_hashtable *env_hashtable)
{
	int index;

	index = 0;
	if (ft_arraylen(argv) == 1)
	{
		while(index < env_hashtable->length)
		{
			if (env_hashtable->element_array[index])
			{
				printf("%s=", env_hashtable->element_array[index]->key);
				printf("\"%s\"", env_hashtable->element_array[index]->value);
				printf("\n");
			}
			index++;
		}
		return NULL;
	}
	else
	{

	}
	return (env_hashtable);
}
