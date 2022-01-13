/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:58 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/13 18:19:43 by jahuang          ###   ########.fr       */
/*   Updated: 2022/01/11 16:24:48 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* function to print out token_list for testing purpous. */
static void	ft_print_token_list(t_token *token_list)
{
	t_token	*holder;

	holder = token_list;
	while (holder)
	{
		printf("token type: %d\n", holder->token_type);
		printf("token value: %s\n\n", holder->value);
		holder = holder->next;
	}
	return ;
}

static void	ft_print_title(void)
{
	char	buffer[2048 + 1];
	int		fd;
	int		ret;

	fd = open("./others/prompt_string.txt", O_RDONLY);
	ret = read(fd, buffer, 2048);
	buffer[ret] = '\0';
	printf("%s\n", buffer);
}

void	ft_minishell_loop(char *prompt)
{
	char	*input;
	t_token	*token_list;

	while (1)
	{
		input = readline(prompt);
		if (!input)
		{
			printf("Banana~~~!\n");
			exit(0);
		}
		if (ft_strlen(input) != 0)
			add_history(input);
		if (ft_check_quote(input) == 1)
			printf("Syntaxe Error: Unclosed quote.\n");
		else
		{
			token_list = ft_lexer(input);
			ft_print_token_list(token_list);
			ft_free_token_list(token_list);
			free(input);
		}
	}
	return ;
}

int	main(int argc, char **argv, char **env)
{
	char	*prompt;

	(void)argc;
	(void)argv;
	(void)env;
	prompt = "\n|( o)═( o)| >";
	ft_print_title();
	ft_minishell_loop(prompt);
	return (0);
}
