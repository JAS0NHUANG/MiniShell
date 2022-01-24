/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:39:26 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/24 17:07:03 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// NEED JASON TO CHANGE THE PATH////

/*
char	*ft_change_old_pwd(char *buf, t_hastable *env_table)
{
	env_ht = ft_change_value(env_table, "PATH", buf, 0);
	buf = OLD_PWD
}
*/

/*
char	*ft_change_new_pwd(void)
{
	char	*tmp;

	tmp = getcwd(tmp, BUFFER_SIZE);
	return (tmp);
}
*/

void	ft_cd_42(char **str, t_hashtable *env_table)
{
	(void)env_table;
	char	*tmp;

	tmp = NULL;
	tmp = getcwd(tmp, BUFFER_SIZE);
	chdir(str[1]);

//	ft_change_old_pwd(buf, env_table);
//	ft_change_new_pwd();
	free(tmp);
}

int		ft_cd(char **str, t_hashtable *env_table)
{
	struct stat	*buf;

	buf = NULL;
	if (ft_strlen(str[1]) > 255)
		printf("cd: %s file name too long \n", str[1]);
	else if (str[2] != 0)
		printf("cd: too many arguments\n");
	else if (!access(str[1], F_OK))
		printf("cd: %s: No such file or directory\n", str[1]);
	else if (lstat((const char *)str[1], buf) == -1)
		printf("Error\n");
	else if (!S_ISDIR(buf->st_mode))
		printf("cd: not a directory: %s\n", str[1]);
	else if (!access(str[1], X_OK))
		printf("cd: permission denied: %s", str[1]);
	else
	{
		ft_cd_42(str, env_table);
		return (1);
	}
	return (0);
}
