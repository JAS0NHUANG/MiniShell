/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:29:00 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/23 21:27:49 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include <stdlib.h>
# include <stddef.h>

/*
** hashtable structs
*/

typedef struct s_element
{
	char	*key;
	char	*value;
}		t_element;

typedef struct s_hashtable
{
	t_element	**element_array;
	int			length;
}		t_hashtable;

/*
** hashtable functions
*/

t_hashtable	*ft_create_hashtable(int length);
t_element	*ft_create_element(char *key, char *value);
void		ft_print_hashtable(t_hashtable *hashtable, char *delimeter);
int			ft_monkey_hash(char *str, int length);
char		*ft_get_value(t_hashtable *hashtable, char *key);
void		ft_free_hashtable(t_hashtable *hashtable);
void		ft_free_element(t_element *element);
t_hashtable	*ft_delete_element(t_hashtable *ht, char *key);
t_hashtable	*ft_change_value(t_hashtable *ht, char *key,
				char *value, int is_append);
t_hashtable	*ft_add_element(t_hashtable *ht, char *key, char *value);
void		ft_print_env(t_hashtable *env_hashtable, int is_export);

#endif
