/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:57:33 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/04 16:31:00 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Get the next prime number.
*/

int	ft_next_prime(int nbr)
{
	int	result;

	result = nbr;
	while (ft_is_prime(result) == 0)
		result++;
	return (result);
}
