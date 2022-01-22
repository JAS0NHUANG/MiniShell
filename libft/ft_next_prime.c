/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:57:33 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/15 04:13:25 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_next_prime(int nbr)
{
	int	result;

	result = nbr;
	while (ft_is_prime(result) == 0)
		result++;
	return (result);
}
