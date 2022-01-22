/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:03:00 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/22 15:46:35 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_exact_path(char *cmd, char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], cmd);
printf("TEST PATH TESTED ===> %s\n", tmp);
		if (access(tmp, F_OK) == 0)
		{
			return (tmp);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

void	ft_execve_1(t_ast *tree, char **cmd)
{
	int		result;

	result = execve(ft_exact_path(tree->value[0], cmd), tree->value, NULL);
	if (result == -1)
	{
		perror("command not found");
	}
}

int		ft_execve_cmd(t_ast *tree, t_hashtable *table)
{
	char	**str;
	char	*path;
	int		i;
	char	*tmp;

	i = 0;
(void)tree;	
	path = ft_get_value(table, "PATH");
	str = ft_split(path, ':');
	while (str[i])
	{
		tmp = str[i];
		str[i] = ft_strjoin(str[i], "/");
		free(tmp);
		i++;
	}
	ft_execve_1(tree, str);
	return (1);
}
