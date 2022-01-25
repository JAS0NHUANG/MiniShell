#include "minishell.h"

int	ft_execute_builtin(t_ast *tree, t_hashtable *table)
{
	if (ft_strncmp(tree->value[0], "cd", 2) == 0)
		exit(ft_cd(tree->value, &table));
	else if (ft_strncmp(tree->value[0], "echo", 4) == 0)
	{
		ft_echo(tree->value);
		exit(0);
	}
	else if (ft_strncmp(tree->value[0], "env", 3)== 0)
		exit(ft_env(tree->value, table));
	else if (ft_strncmp(tree->value[0], "export", 6) == 0)
		exit(0);
	else if (ft_strncmp(tree->value[0], "exit", 4) == 0)
		exit(0);
	else if (ft_strncmp(tree->value[0], "pwd", 3) == 0)
		exit(ft_pwd());
	else if (ft_strncmp(tree->value[0], "unset", 5) == 0)
	{
		table = ft_unset(tree->value, table);
		exit(0);
	}
	else
		return (-1);
	return (0);
}
