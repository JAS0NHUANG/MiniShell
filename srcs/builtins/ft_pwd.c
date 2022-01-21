/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:40:57 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/21 14:10:44 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*str;

	str = NULL;
	str = getcwd(str, BUFFER_SIZE);
	if (str == NULL)
	{
		write(1, "cd: An error occured while getting cwd\n", 39);
		return (EXIT_FAILURE);
	}
	else
		printf("Current working directory: %s\n", str);
	free(str);
	return (EXIT_SUCCESS);
}
