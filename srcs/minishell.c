/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:58 by antton-t          #+#    #+#             */
/*   Updated: 2021/12/14 17:52:02 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <unistd.h>

#include "lexer.h"

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

int main()
{
	char *input;
	char *prompt;
	/* I think token_list is better then start? */
	t_token	*token_list;

	prompt = "\n|( o)═( o)| >";
	ft_print_title();
	while (1)
	{
		input = readline(prompt);
		/* this functionality can be added after?
		if (strlen(line) != 0)
			add_history(line);
		*/
		printf("User input: %s\n", input);
		token_list = ft_lexer(input);
		while (token_list != NULL)
		{
			printf("%s \n",token_list->value);
			token_list = token_list->next;
		}
	}
}
