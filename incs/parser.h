#ifndef PARSER_H
# define PARSER_H

enum	e_node_type {
	NODE_CMD = 0,
	NODE_PIPE,
	NODE_REDIR,
}

typedef struct	s_redir {
	char			*value;
	int				redir_type;
	struct s_redir	*prev;
	struct s_redir	*next;
}				t_redir;

typedef struct	s_ast {
	char			**value;
	t_redir			*redir_list;
	int				node_type;
	struct s_ast	*left;
	struct s_ast	*right;
}				t_ast;

t_ast	*ft_create_ast(t_token *list);
int		ft_check_redir(int	nb_elem, t_token *token_list);

#endif
