/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:58 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/24 15:34:48 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* function to print out token_list for testing purpous. */
void	ft_print_token_list(t_token *token_list)
{
	t_token	*holder;

	holder = token_list;
	while (holder)
	{
		dprintf(2, "token type: %d\n", holder->token_type);
		dprintf(2, "token value: %s\n\n", holder->value);
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

void	ft_print_tree(t_ast *ast_tree)
{
	if (!ast_tree->left)
	{
		printf("THE TREE: ~~~~~~~~~~~~~~~~~~~~\n");
		if (ast_tree->value)
		{
			ft_putstr_fd("left cmd:", 2);
			ft_putstr_array(ast_tree->value);
		}
		return ;
	}
	if (ast_tree->left)
		ft_print_tree(ast_tree->left);
	if (ast_tree->right->value)
	{
		ft_putstr_fd("right cmd:", 2);
		ft_putstr_array(ast_tree->right->value);
	}
}

int	ft_check_pipe(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '|')
		return (-1);
	while (str[i])
		i++;
	i--;
	if (str[i] == '|')
		return (-1);
	else
		return (1);
}

void	ft_minishell_2(char *input, t_hashtable *env_hashtable)
{
	t_token	*token_list;
	t_ast	*ast_tree;

	token_list = ft_lexer(input);
	dprintf(2, "input: %s\n", input);
	ft_print_token_list(token_list);
	if (ft_check_token_list(token_list) == 1)
	{
		ast_tree = ft_create_ast(token_list);
		ft_print_tree(ast_tree);
		ft_handle_pipe(ast_tree, env_hashtable);
		ft_free_ast(ast_tree);
	}
	ft_free_token_list(token_list);
	dprintf(2, "env input: %s\n", ft_get_value(env_hashtable, input));
	free(input);
}

void	ft_minishell_loop(char *prompt, t_hashtable *env_hashtable)
{
	char	*input;

	while (1)
	{
		input = readline(prompt);
		if (input == NULL)
		{
			printf("exit\n");
			exit(0);
		}
		else
		{
			if (ft_strlen(input) != 0)
				add_history(input);
			if (ft_check_pipe(input) == -1)
				printf("syntax error near unexpected token `|'\n");
			else if (ft_check_quote(input) == 1)
				printf("Syntaxe Error: Unclosed quote.\n");
			else
				ft_minishell_2(input, env_hashtable);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	char		*prompt;
	t_hashtable	*env_hashtable;

	(void)argc;
	(void)argv;
	env_hashtable = ft_create_env_hashtable(env);
	prompt = "\n|( o)═( o)| >";
	ft_print_title();
	ft_minishell_loop(prompt, env_hashtable);
	ft_free_hashtable(env_hashtable);
	return (0);
}
