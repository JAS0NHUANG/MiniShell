/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:58 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/11 16:24:48 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* function to print out token_list for testing purpous. */
static void ft_print_token_list(t_token *token_list)
{
	t_token *holder;

	holder = token_list;
	while(holder)
	{
		printf("token type: %d\n", holder->token_type);
		printf("token value: %s\n\n", holder->value);
		holder = holder->next;
	}
	return ;
}

static void ft_print_title(void)
{
	char buffer[2048 + 1];
	int	fd;
	int	ret;

	fd = open("./others/prompt_string.txt", O_RDONLY);
	ret = read(fd, buffer, 2048);
	buffer[ret] = '\0';
	printf("%s\n", buffer);
}

int main(int argc, char **argv, char **env)
{
	char *input;
	char *prompt;
	(void)	argc;
	(void)	argv;
	(void)	env;
	t_token	*token_list;

	prompt = "\n|( o)═( o)| >";
	ft_print_title();
	while (1)
	{
		input = readline(prompt);
		printf("User input: %s\n", input);
		if (ft_strlen(input) != 0)
			add_history(input);
		if (ft_check_quote(input) == 1)
			printf("Syntaxe Error: Unclosed quote.\n");
		else
		{
			token_list = ft_lexer(input);
			ft_print_token_list(token_list);
		}
	}
	return (0);
}
