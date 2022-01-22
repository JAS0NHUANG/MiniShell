/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:03:52 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/18 16:28:59 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

enum	e_char_type {
	CHAR_GENERAL = -1,
	CHAR_PIPE = '|',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_DOLLER = '$',
	CHAR_S_QUOTE = 39,
	CHAR_D_QUOTE = '"',
};

enum	e_token_type {
	TOKEN_WORD = 0,
	TOKEN_PIPE,
	TOKEN_GREATER,
	TOKEN_GREATGREATER,
	TOKEN_LESSER,
	TOKEN_LESSLESSER,
};

typedef struct s_token {
	char			*value;
	int				token_type;
	struct s_token	*prev;
	struct s_token	*next;
}		t_token;

t_token		*ft_lexer(char *input);
t_token		*ft_fill_list(t_token *token_list, char *input, int token_len);
void		ft_free_token_list(t_token *token_list);
int			ft_get_token_len(char *input);
int			ft_check_quote(char *input);

#endif
