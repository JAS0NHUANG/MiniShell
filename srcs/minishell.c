/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:58 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/27 02:37:21 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_run_single_cmd(t_ast *ast_tree, t_hashtable **env_hashtable, t_token *token_list)
{
	if (ft_strncmp("exit", ast_tree->value[0], 4) == 0)
		ft_exit(ast_tree->value, ast_tree, *env_hashtable, token_list);
	if (ft_strncmp("export", ast_tree->value[0], 6) == 0)
		*env_hashtable = ft_export(ast_tree->value, *env_hashtable);
	if (ft_strncmp("cd", ast_tree->value[0], 2) == 0)
		ft_cd(ast_tree->value, env_hashtable);
	if (ft_strncmp("unset", ast_tree->value[0], 5) == 0)
		*env_hashtable = ft_unset(ast_tree->value, *env_hashtable);
	else
		ft_handle_pipe(ast_tree, *env_hashtable);
}

void	ft_run_cmd(char *input, t_hashtable **env_hashtable)
{
	t_token *token_list;
	t_ast	*ast_tree;

	token_list = ft_lexer(input);
	ast_tree = ft_create_ast(token_list);
	/*
	ft_test(token_list, ast_tree, env_hashtable);
	*/
	if (!ast_tree->left && !ast_tree->right)
		ft_run_single_cmd(ast_tree, env_hashtable, token_list);
	else
		ft_handle_pipe(ast_tree, *env_hashtable);
	if (ast_tree)
		ft_free_ast(ast_tree);
	if (token_list)
		ft_free_token_list(token_list);
}

int	ft_check_syntax_error(char *input)
{
	if (ft_check_quote(input) == 1)
	{
		printf("Syntaxe Error: Unclosed quote.\n");
		return (1);
	}
	return (0);

}

void	ft_minishell_loop(char *prompt, t_hashtable **env_hashtable, char **input)
{
	while (1)
	{
		*input = readline(prompt);
		if (!*input)
		{
			printf("exit\n");
			exit(0);
		}
		if (ft_strlen(*input) == 0)
		{
			free(*input);
			continue ;
		}
		add_history(*input);
		if (ft_check_syntax_error(*input) == 1)
		{
			free(*input);
			continue ;
		}
		ft_run_cmd(*input, env_hashtable);
		if (*input)
			free(*input);
	}
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

int	main(int argc, char **argv, char **env)
{
	char		*prompt;
	t_hashtable	*env_hashtable;
	char		*input;

	(void)argc;
	(void)argv;
	env_hashtable = ft_create_env_hashtable(env);
	printf("\n");
	prompt = "|( o)═( o)| >";
	ft_print_title();
	input = NULL;
	ft_minishell_loop(prompt, &env_hashtable, &input);
	if (env_hashtable)
		ft_free_hashtable(env_hashtable);
	return (0);
}
