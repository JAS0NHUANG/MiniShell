/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:58 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/22 02:05:35 by jahuang          ###   ########.fr       */
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
	close(fd);
}

void	ft_print_tree(t_ast *ast_tree)
{
	if (!ast_tree->left)
	{
		printf("THE TREE: ~~~~~~~~~~~~~~~~~~~~\n");
		if (ast_tree->value)
		{
			ft_putstr_fd("left cmd:", 1);
			ft_putstr_array(ast_tree->value);
		}
		return ;
	}
	if (ast_tree->left)
		ft_print_tree(ast_tree->left);
	if (ast_tree->right->value)
	{
		ft_putstr_fd("right cmd:", 1);
		ft_putstr_array(ast_tree->right->value);
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
			printf("exit\n");
			exit(0);
		}
		if (ft_strlen(input) == 0)
		{
			free(input);
			continue ;
		}
		add_history(input);
		if (ft_check_quote(input) == 1)
			printf("Syntaxe Error: Unclosed quote.\n");
		else
		{
			token_list = ft_lexer(input);
			printf("input: %s\n", input);
			ft_print_token_list(token_list);
			ast_tree = ft_create_ast(token_list);
			ft_print_tree(ast_tree);
			ft_putstr_fd("still ok", 1);
			if (ast_tree->left && ast_tree->right)
			{
				env_hashtable = ft_export(ast_tree->left->value, env_hashtable); 
				printf("left value : %s\n", ast_tree->left->value[1]);
				printf("right value : %s\n", ast_tree->right->value[1]);
				env_hashtable = ft_unset(ast_tree->right->value, env_hashtable); 
			}
			ft_free_ast(ast_tree);
			ft_free_token_list(token_list);
		}
		free(input);
	}
	return ;
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
