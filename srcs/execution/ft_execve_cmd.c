/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:03:00 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/31 17:16:13 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_handle_sigint(int sg)
{
	if (sg == 2)
	{
		write(1, "\n", 1);
		g_exit_code = 130;
		return ;
	}
	return ;
}

void	ft_error_exit(char *exact_path)
{
	int		path_len;
	char	*err_msg;
	char	*tmp;

	path_len = ft_strlen(exact_path);
	err_msg = NULL;
	err_msg = ft_strjoin("Minishell: ", exact_path);
	tmp = err_msg;
	err_msg = ft_strjoin(err_msg, " command not found\n");
	write(2, err_msg, 30 + path_len);
	if (exact_path)
		free(exact_path);
	free(tmp);
	free(err_msg);
	exit (127);
}

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

	signal(SIGINT, &ft_handle_sigint);
	result = 0;
	exact_path = ft_exact_path(tree->value[0], paths_array);
	if (!exact_path && tree->value[0])
		exact_path = ft_strdup(tree->value[0]);
	if (exact_path && access(exact_path, F_OK) != 0)
		ft_error_exit(exact_path);
	if (exact_path)
	{
		result = execve(exact_path, tree->value, NULL);
		if (result == -1)
		{
			ft_putstr_fd(exact_path, 2);
			perror(": Minishell");
			free(exact_path);
			exit(126);
		}
	}
	if (exact_path)
		free(exact_path);
	if (paths_array)
		ft_free_char_array(paths_array);
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
	else
		ft_error_exit(tree->value[0]);
	ft_execution(tree, paths_array);
	return (1);
}
