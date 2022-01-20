#include "hashtable.h"

t_hashtable	*ft_add_element(t_hashtable *ht, char *key, char *value, int arrlen)
{
	int	hash_index;

	hash_index = ft_monkey_hash(key, arrlen);
	while (ht->element_array[hash_index])
		hash_index = (hash_index + 1) % arrlen;
	ht->element_array[hash_index] = ft_create_element(key, value);
	return (ht);
}
