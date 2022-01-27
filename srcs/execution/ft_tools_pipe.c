/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:03:00 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/27 13:46:52 by antton-t         ###   ########.fr       */
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
		if (access(tmp, F_OK) == 0)
{printf("echo ==> %s\n", tmp);
			return (tmp);
}
		free(tmp);
		i++;
	}
	return (NULL);
}

void	ft_execve_1(t_ast *tree, char **paths)
{
	int		result;
	char	*exact_path;

	exact_path = ft_exact_path(tree->value[0], paths);
	if (!exact_path)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(tree->value[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	result = execve(exact_path, tree->value, NULL);
	if (result == -1)
	{
		perror("Minishell: ");
		exit(1);
	}
}

int	ft_execve_cmd(t_ast *tree, t_hashtable *table)
{
	char	**str;
	char	*path;
	int		i;
	char	*tmp;

	i = 0;
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
