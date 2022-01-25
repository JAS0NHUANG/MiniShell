/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:39:26 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/25 09:57:55 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// NEED JASON TO CHANGE THE PATH////

static void	ft_change_new_pwd(t_hashtable **env_table)
{
	char	*tmp;

	tmp = NULL;
	tmp = getcwd(tmp, BUFFER_SIZE);
	*env_table = ft_change_value(*env_table, "PWD", tmp, 0);
	if (tmp)
		free(tmp);
}

static void	ft_do_cd(char **str, t_hashtable **env_table)
{
	char	*tmp;

	tmp = NULL;
	tmp = getcwd(tmp, BUFFER_SIZE);
	if (chdir(str[1]) == -1)
	{
		if (tmp)
			free(tmp);
		perror("Minishell: cd: ");
		return ;
	}
	*env_table = ft_change_value(*env_table, "OLDPWD", tmp, 0);
	ft_change_new_pwd(env_table);
	free(tmp);
}

static int		ft_check_error(char **str)
{
	struct stat	*buf;
	char	*err_msg;

	err_msg = NULL;
	buf = calloc(1, sizeof(struct stat));
	if (ft_strlen(str[1]) > 255)
		err_msg = ft_strjoin(str[1], "file name too long");
	else if (str[2] != 0)
		err_msg = ft_strdup("too many arguments");
	else if (access(str[1], F_OK) == -1)
		err_msg = ft_strjoin(str[1], " No such file or directory");
	else if (lstat((const char *)str[1], buf) == -1)
		err_msg = ft_strdup("Error");
	else if (access(str[1], X_OK) == -1)
		err_msg = ft_strjoin("permission denied: ", str[1]);
	if (err_msg)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(err_msg, 2);
		ft_putstr_fd("\n", 2);
		free(err_msg);
		return (1);
	}
	return (0);
}

int	ft_cd(char **str, t_hashtable **env_table)
{
	if (ft_check_error(str))
		return (1);
	else
	{
		ft_do_cd(str, env_table);
		return (0);
	}
	return (1);
}
