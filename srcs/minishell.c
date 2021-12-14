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

int main()
{
	char *line;
	char *prompt;

	prompt = "\n|( o)═( o)| >";
	ft_print_title();
	while (1)
	{
		line = readline(prompt);
		printf("User input: %s\n", line);
	}

}
