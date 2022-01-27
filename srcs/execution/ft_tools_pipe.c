/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:03:00 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/27 02:22:31 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_exact_path(char *cmd, char **paths_array)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!cmd)
		return (NULL);
	while (paths_array[i])
	{
		tmp = ft_strjoin(paths_array[i], cmd);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}

void	ft_execution(t_ast *tree, char **paths_array)
{
	int		result;
	char	*exact_path;

	exact_path = ft_exact_path(tree->value[0], paths_array);
	if (!exact_path)
		exact_path = ft_strdup(tree->value[0]);
	result = execve(exact_path, tree->value, NULL);
	if (result == -1)
	{
		perror("Minishell: ");
		exit(1);
	}
	if (exact_path)
		free(exact_path);
}

int	ft_execve_cmd(t_ast *tree, t_hashtable *table)
{
	char	*paths_str;
	char	**paths_array;
	int		i;
	char	*tmp;

	i = 0;
	paths_array = NULL;
	paths_str = ft_get_value(table, "PATH");
	if (paths_str)
	{
		paths_array = ft_split(paths_str, ':');
		while (paths_array[i])
		{
			tmp = paths_array[i];
			paths_array[i] = ft_strjoin(paths_array[i], "/");
			free(tmp);
			i++;
		}
	}
	ft_execution(tree, paths_array);
	return (1);
}
