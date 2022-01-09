#include "minishell.h"

int	ft_arraylen(char **str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}
