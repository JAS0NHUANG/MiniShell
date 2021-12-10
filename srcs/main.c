#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <unistd.h>


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

	fd = open("./minion_title.txt", O_RDONLY);
	ret = read(fd, buffer, 2048);
	buffer[ret] = '\0';
	printf("%s", buffer);
}

int main()
{
	char *line;
	char *prompt;

	prompt = "|( o)═( o)| >";
	ft_print_title();
	while (1)
	{
		line = readline(prompt);
		printf("line: %s\n", line);
	}
}
