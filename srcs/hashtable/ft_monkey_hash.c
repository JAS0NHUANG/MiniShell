/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monkey_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:48:19 by jahuang           #+#    #+#             */
/*   Updated: 2021/12/09 11:05:41 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	My cute "ft_monkey_hase" funcition. (^ ^)
**	                                     (o)
*/
int	ft_monkey_hash(char *str, int length)
{
	int	index;
	int	result;
	int	monkey_number;

	index = 0;
	result = 0;
	monkey_number = 89;
	while (str[index])
	{
		result += monkey_number * (int)str[index] * index;
		index++;
	}
	return (result % length);
}
