/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:39:26 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/27 16:02:19 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_update_pwd(t_hashtable **env_table, char *old_pwd)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, BUFFER_SIZE);
	*env_table = ft_ch_value(*env_table, "PWD", pwd, 0);
	*env_table = ft_ch_value(*env_table, "OLDPWD", old_pwd, 0);
	if (pwd)
		free(pwd);
}

static void	ft_do_cd(char **str_array, t_hashtable **env_table)
{
	char	*old_pwd;

	old_pwd = NULL;
	old_pwd = getcwd(old_pwd, BUFFER_SIZE);
	if (chdir(str_array[1]) == -1)
	{
		if (old_pwd)
			free(old_pwd);
		perror("Minishell: cd: ");
		return ;
	}
	ft_update_pwd(env_table, old_pwd);
	free(old_pwd);
}

static char	*ft_make_err_msg(char **str_array, struct stat **buf)
{
	char		*err_msg;

	err_msg = NULL;
	if (!str_array[1])
		err_msg = ft_strdup("please provide a relative or absolute path");
	else if (ft_strlen(str_array[1]) > 255)
		err_msg = ft_strjoin(str_array[1], "file name too long");
	else if (str_array[2] != 0)
		err_msg = ft_strdup("too many arguments");
	else if (access(str_array[1], F_OK) == -1)
		err_msg = ft_strjoin(str_array[1], " No such file or directory");
	else if (lstat((const char *)str_array[1], *buf) == -1)
		err_msg = ft_strdup("Error");
	else if (access(str_array[1], X_OK) == -1)
		err_msg = ft_strjoin("permission denied: ", str_array[1]);
	return (err_msg);
}

static int	ft_check_error(char **str_array)
{
	struct stat	*buf;
	char		*err_msg;

	err_msg = NULL;
	buf = calloc(1, sizeof(struct stat));
	err_msg = ft_make_err_msg(str_array, &buf);
	if (buf)
		free(buf);
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

int	ft_cd(char **str_array, t_hashtable **env_table)
{
	if (ft_check_error(str_array))
	{
		g_exit_code = 1;
		return (1);
	}
	ft_do_cd(str_array, env_table);
	g_exit_code = 0;
	return (0);
}
