#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <unistd.h>

#include "../incs/lexer.h"

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

t_token	*ft_token_create(void)
{
	t_token	*out;

	out = malloc(sizeof(t_token));
	if (out == NULL)
		return (NULL);
	out->next = NULL;
	out->value = NULL;
	return (out);
}

int	ft_count_size(char *src, int i)
{
	int	size;

	size = 0;
	while (src[i] != ' ' || src[i] != '|' || src[i] != '<' || src[i] != '>')
	{
		i++;
		size++;
	}
	return (size);
}

t_token	*ft_fill_chain_lst(char *str, int i, int count)
{
	t_token	*out;
	int		j;

	j = 0;
	out = ft_token_create();
	out->value = (char *)malloc(sizeof(char) * (count + 1));
	if (out->value == NULL)
		return (NULL);
	while (j < count)
	{
		out->value[j] = str[i];
		j++;
		i++;
	}
	out->value[j] = 0;
	return (out);
}

t_token *ft_fill_lst(t_token *out, char *src, int i, int count)
{
	t_token	*ptr;
	int		j;
	t_token *new;

	j = 0;
	ptr = out;
	while (ptr->next != NULL)
		ptr = ptr->next;
	new = ft_token_create();
	if (new == NULL)
		return (NULL);
	ptr->next = new;
	while (j < count)
	{
		new->value[j] = src[i];
		j++;
		i++;
	}
	new->value[j] = 0;
	return (out);

}

t_token	*ft_start_lexer(char *line)
{
	t_token	*out;
	int		i;
	int		count;

	i = 0;
	while (line[i])
	{
		count = ft_count_size(line, i);
		if (i == 0)
			out = ft_fill_chain_lst(line, i, count);
		else
			out = ft_fill_lst(out, line, i, count);
		i = i + count;
	}

	return (out);
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
		printf("line: %s\n", line);
		start = ft_start_lexer(line);
	}
}
