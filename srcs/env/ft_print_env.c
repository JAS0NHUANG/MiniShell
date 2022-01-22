#include "minishell.h"

void	ft_print_env(t_hashtable *env_hashtable, int is_export)
{
	int		index;
	t_element	*env_element;
	

	index = 0;
	while(index < env_hashtable->length)
	{
		if (env_hashtable->element_array[index])
		{
			env_element = env_hashtable->element_array[index];
			if (is_export)
				printf("export ");
			printf("%s=", env_element->key);
			if (is_export)
				printf("\"%s\"", env_element->value);
			else
				printf("%s", env_element->value);
			printf("\n");
		}
		index++;
	}
}
