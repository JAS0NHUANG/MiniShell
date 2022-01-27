/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:58 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/27 14:38:18 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	ft_tree2(t_ast *tree, t_hashtable *table, t_token *token_list)
{
	if (ft_strncmp("exit", tree->value[0], 5) == 0)
		ft_exit(tree->value, tree, table, token_list);
	if (ft_strncmp("export", tree->value[0], 7) == 0)
		ft_export(tree->value, table);
	else
		ft_handle_pipe(tree, table);
}

void	ft_minishell_tree(t_hashtable *env_hashtable, t_token *token_list)
{
	t_ast	*ast_tree;
	int		ret;

	ast_tree = NULL;
	ret = ft_check_pipe(token_list);
	if (ret != 0)
	{
		if (ret == -1)
			printf("Syntaxe Error : Minion Shell Err0r\n");
		return ;
	}
	else
	{
		ft_handle_heardoc(token_list);
		ast_tree = ft_create_ast(token_list);
		if (!ast_tree->left && !ast_tree->right)
			ft_tree2(ast_tree, env_hashtable, token_list);
		else
			ft_handle_pipe(ast_tree, env_hashtable);
		if (ast_tree)
			ft_free_ast(ast_tree);
		if (token_list)
			ft_free_token_list(token_list);
	}
}

void	ft_minishell_loop(char *prompt, t_hashtable *env_hashtable)
{
	char	*input;
	t_token	*token_list;

	token_list = NULL;
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
			ft_minishell_tree(env_hashtable, token_list);
		}
		free(input);
	}
}

void	ft_handle_signal(int s)
{
	(void)s;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(int argc, char **argv, char **env)
{
	char		*prompt;
	t_hashtable	*env_hashtable;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_handle_signal);
	(void)argc;
	(void)argv;
	env_hashtable = ft_create_env_hashtable(env);
	printf("\n");
	prompt = "|( o)═( o)| >";
	ft_print_title();
	ft_minishell_loop(prompt, env_hashtable);
	if (env_hashtable)
		ft_free_hashtable(env_hashtable);
	return (0);
}
