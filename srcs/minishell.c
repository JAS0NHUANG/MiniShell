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

void	ft_putstr_fd(char *str, int fd)
{
	while(*str)
	{
		write(fd, str, 1);
		str++;
	}
}

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
	char *line;
	char *prompt;
	t_token	*start;

	prompt = "\n|( o)═( o)| >";
	ft_print_title();
	while (1)
	{
		line = readline(prompt);
		if (strlen(line) != 0)
			add_history(line);
		printf("line: %s\n", line);
		start = ft_start_lexer(line);

while (start != NULL)
{
	printf("%s \n",start->value);
	start = start->next;
}
		//ft_free(start);
	}

}
