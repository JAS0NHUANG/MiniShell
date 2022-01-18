#include "minishell.h"

t_ast	*ft_create_ast(t_token *token_list)
{
	t_ast	*ast_tree;
	int		nb_element;
	int		nb_pipe;

	ast_tree = NULL;
	nb_pipe = ft_count_pipe(token_list);
	while (nb_pipe)
	{
		nb_element = ft_count_element(token_list);
		ast_tree = 
	}

}
