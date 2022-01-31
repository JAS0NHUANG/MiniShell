/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <jahuang@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 06:59:39 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/30 06:59:51 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int	ft_count_len(unsigned int nbr)
{
	if (nbr < 10)
		return (1);
	return (1 + ft_count_len(nbr / 10));
}

static void	ft_itoa_writer(char *result, int nbr_len, unsigned int nbr)
{
	result[nbr_len - 1] = (char)(nbr % 10) + '0';
	if (nbr < 10)
		return ;
	ft_itoa_writer(result, nbr_len - 1, nbr / 10);
}

char		*ft_itoa(int n)
{
	unsigned int	n_holder;
	int				negatif;
	int				nbr_len;
	char			*result;

	negatif = 1;
	nbr_len = 0;
	if (n < 0)
	{
		negatif = -1;
		nbr_len = 1;
	}
	n_holder = n * negatif;
	if ((n_holder > 2147483648) || \
		(n_holder > 2147483647 && negatif == 1))
		return (NULL);
	nbr_len += ft_count_len(n_holder);
	result = (char *)malloc((nbr_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_itoa_writer(result, nbr_len, n_holder);
	if (negatif < 0)
		result[0] = '-';
	result[nbr_len] = '\0';
	return (result);
}
