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

typedef struct	s_token {
	char *value;
	int	token_type;
	struct s_token *prev;
	struct s_token *next;
}				t_token;

typedef struct b_inary {
	char	**value_left;
	char	**value_right;
	struct	b_inary *next;
	struct	b_inary *prev;
}				t_inary;

t_token	*ft_lexer(char *input);
void	ft_parsing_dollar(t_token *token_list, char **env);
t_inary *ft_fill_right_value(int nb_elem, t_token *list, t_inary *tree);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
void	ft_parsing_single_quote(t_token *token_lst);
t_inary	*ft_create_tree(t_token *token_list);
char	*ft_strcpy_ast(char *src);
t_inary	*ft_create_first_node(int nb_elem, t_token *list);
#endif
