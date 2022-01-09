/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:58 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/02 17:16:16 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_print_title(void)
{
	char buffer[2048 + 1];
	int	fd;
	int	ret;

	fd = open("./others/prompt_string.txt", O_RDONLY);
	ret = read(fd, buffer, 2048);
	buffer[ret] = '\0';
	printf("%s", buffer);
}

int main(int argc, char **argv, char **env)
{
	char *input;
	char *prompt;
	(void)	argc;
	(void)	argv;
	/* I think token_list is better then start? */
	t_token	*token_list;

	prompt = "\n|( o)═( o)| >";
	ft_print_title();
	ft_create_env_hashtable(env);
	while (1)
	{
		input = readline(prompt);
		/* this functionality can be added after?
		if (strlen(line) != 0)
			add_history(line);
		*/
		printf("User input: %s\n", input);
		token_list = ft_lexer(input);
		ft_parsing_dollar(token_list, env);
		ft_parsing_single_quote(token_list);
	}
}
