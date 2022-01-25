#include "minishell.h"

void	ft_redir_out(char *file)
{
	int		fd;

	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		printf("Error open file\n");
	else
	{
		dup2(fd, STDOUT_FILENO);
		close (fd);
	}
}

void	ft_append_out(char *file)
{
	int		fd;

	if ((fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644)) == -1)
		printf("Error open file\n");
	else
	{
	dup2(fd, STDOUT_FILENO);
	close(fd);
	}
}

void	ft_redir_in(char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY, 0)) == -1)
		printf("Error open file\n");
	else
	{
	dup2(fd, 0);
	close(fd);
	}
}

void	ft_handle_redir(t_ast *node)
{
	t_redir	*tmp;

	tmp = node->redir_list;
	while (tmp)
	{
		if (tmp->redir_type == REDIR_OUT)
			ft_redir_out(tmp->value);
		else if (tmp->redir_type == REDIR_APPEND_OUT)
			ft_append_out(tmp->value);
		else if (tmp->redir_type == REDIR_IN)
			ft_redir_in(tmp->value);
		tmp = tmp->next;
	}
}
