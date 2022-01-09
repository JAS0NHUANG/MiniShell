#include "minishell.h"

int	ft_is_prime(int nbr)
{
	int	mod;

	mod = 2;
	while (mod < nbr / 2)
	{
		if (nbr % mod == 0)
			return (0);
		mod++;
	}
	return (1);
}
