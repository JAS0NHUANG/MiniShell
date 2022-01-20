/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:58 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/20 00:39:26 by jahuang          ###   ########.fr       */
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

void	ft_print_tree(t_ast *ast_tree)
{
	int	index;

	if (!ast_tree->left)
	{
		printf("THE TREE: ~~~~~~~~~~~~~~~~~~~~\n");
		if (ast_tree->value)
		{
			printf("left cmd:");
			index = 0;
			while (ast_tree->value[index])
			{
				printf(" %s ", ast_tree->value[index]);
				index++;
			}
			printf("\n");
		}
		return ;
	}
	if (ast_tree->left)
		ft_print_tree(ast_tree->left);
	if (ast_tree->right->value)
	{
		printf("right cmd:");
		index = 0;
		while (ast_tree->right->value[index])
		{
			printf(" %s ", ast_tree->right->value[index]);
			index++;
		}
		printf("\n");
	}
}

void	ft_minishell_loop(char *prompt, t_hashtable *env_hashtable)
{
	char	*input;
	t_token	*token_list;
	t_ast	*ast_tree;

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
			printf("input: %s\n", input);
			ft_print_token_list(token_list);
			ast_tree = ft_create_ast(token_list);
			if (ast_tree)
				ft_print_tree(ast_tree);
			ft_free_token_list(token_list);
			printf("env input: %s\n", ft_get_value(env_hashtable, input));
			free(input);
		}
	}
	return ;
}

int	main(int argc, char **argv, char **env)
{
	char	*prompt;
	t_hashtable *env_hashtable;

	(void)argc;
	(void)argv;
	env_hashtable = ft_create_env_hashtable(env);
	prompt = "\n|( o)═( o)| >";
	ft_print_title();
	ft_minishell_loop(prompt, env_hashtable);
	ft_free_hashtable(env_hashtable);
	return (0);
}
