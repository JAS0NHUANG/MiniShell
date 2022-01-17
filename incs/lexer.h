#ifndef LEXER_H
# define LEXER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum char_type {
	CHAR_GENERAL = -1,
	CHAR_PIPE = '|',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_DOLLER = '$',
	CHAR_S_QUOTE = 39,
	CHAR_D_QUOTE = '"',
};

enum token_type {
	TOKEN_WORD = 0,
	TOKEN_PIPE,
	TOKEN_GREATER,
	TOKEN_GREATGREATER,
	TOKEN_LESSER,
	TOKEN_LESSLESSER,
};

enum type_node {
	NODE_CMD = 0,
	NODE_PIPE,
	NODE_LIST,
};

enum list_value {
	LIST_CMD = 0,
	LIST_FILE,
	LIST_GREATER,
	LIST_GREATGREATER,
	LIST_LESSER,
	LIST_LESSLESSER,
};

typedef struct	s_token {
	char	*value;
	int		token_type;
	struct	s_token *prev;
	struct	s_token *next;
}				t_token;

typedef struct	r_dir {
	char	*value;
	int		list_value;
	struct	r_dir *prev;
	struct	r_dir *next;
}				t_dir;

typedef struct b_inary {
	char	**value;
	t_dir	*t_dir;
	int		type_node;
	struct	b_inary *left;
	struct	b_inary *right;
}				t_inary;

t_token	*ft_lexer(char *input);
void	ft_parsing_dollar(t_token *token_list, char **env);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
void	ft_parsing_single_quote(t_token *token_lst);
char	*ft_strcpy_ast(char *src);
t_inary	*ft_create_tree(t_token *list);
int		ft_check_list_dir(int nb_elem, t_token *list);
t_inary	*ft_create_node_list_chain(t_inary *node_out, int count, t_token *list);
void	ft_handle_pipe(t_inary *tree);
int		ft_check_pipe(t_inary *tree);
int		ft_check_input_pipe_end(char *src);
int		ft_check_input(char *src);
#endif
