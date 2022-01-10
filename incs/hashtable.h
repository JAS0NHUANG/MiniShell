/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:29:00 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/10 22:32:24 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

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
	int		length;
}		t_hashtable;

/*
** hashtable functions
*/

t_hashtable	*ft_create_hashtable(int length);
t_element	*ft_create_element(char *key, char *value);
void		ft_print_hashtable(t_hashtable *hashtable, char *delimeter);
int		ft_monkey_hash(char *str, int length);
char		*ft_get_value(t_hashtable *hashtable, char *key);
void		ft_free_hashtable(t_hashtable *hashtable);
int		ft_next_prime(int nbr);
int		ft_is_prime(int nbr);

#endif
