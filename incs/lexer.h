#ifndef LEXER_H
# define LEXER_H

#include <stdlib.h>
#include <stdio.h>

enum char_type {
	CHAR_GENERAL = -1,
	CHAR_PIPE = '|',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_DOLLER = '$',
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
	struct s_token *next;
}				t_token;

t_token	*ft_lexer(char *input);

#endif
