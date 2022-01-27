/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:54:45 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/27 12:13:21 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

enum	e_node_type {
	NODE_CMD = 0,
	NODE_PIPE,
};

enum	e_redir_type {
	REDIR_OUT = 0,
	REDIR_APPEND_OUT,
	REDIR_IN,
	REDIR_HEREDOC,
};

typedef struct s_redir {
	char			*value;
	int				redir_type;
	struct s_redir	*next;
}				t_redir;

typedef struct s_ast {
	char			**value;
	t_redir			*redir_list;
	int				node_type;
	struct s_ast	*left;
	struct s_ast	*right;
}				t_ast;

t_ast	*ft_create_ast(t_token *token_list);
t_redir	*ft_add_redir_node(t_redir *redir_list, t_token *token_list);
void	ft_free_ast(t_ast *ast_tree);

#endif
