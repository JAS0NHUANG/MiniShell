#include "minishell.h"

t_element	*ft_get_element(t_hashtable *ht, char *key)
{

	int			index;
	int			key_len;
	int			table_len;
	int			hash_nbr;
	t_element	**elem_holder;

	index = 0;
	key_len = ft_strlen(key);
	table_len = ht->length;
	hash_nbr = ft_monkey_hash(key, ht->length);
	elem_holder = ht->element_array;
	while (elem_holder[index + hash_nbr] && \
		hash_nbr == ft_monkey_hash(elem_holder[index + hash_nbr]->key, table_len))
	{
		if (ft_strncmp(elem_holder[index + hash_nbr]->key, key, key_len) == 0)
			return (elem_holder[index + hash_nbr]);
		index++;
	}
	return (NULL);
}

t_hashtable	*ft_change_value(t_hashtable *ht, char *key, char *value, int is_append)
{
	t_element	*element;
	char	*value_holder;

	element = ft_get_element(ht, key);
	if (!element)
		return (ht);
	value_holder = element->value;
	if (is_append)
		element->value = ft_strjoin(element->value, value);
	else
		element->value = ft_strdup(value);
	free(value_holder);
	return (ht);
}
