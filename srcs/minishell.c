/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:58 by antton-t          #+#    #+#             */
/*   Updated: 2022/02/01 14:36:29 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_code;

void	ft_handle_input(char *input, t_hashtable **env_ht, char **envp)
{
	t_token	*token_list;
	t_ast	*ast;
	int		fd;

	token_list = ft_lexer(input);
	if (input)
		free(input);
	if (ft_check_syntax_error(token_list) == 0)
	{
		ft_expand_token_list(&token_list, *env_ht);
		ft_handle_heredoc(token_list);
		ast = ft_create_ast(token_list);
		if (!ast->left && !ast->right)
			ft_run_single_cmd(ast, env_ht, token_list, envp);
		else
			ft_handle_pipe(ast, *env_ht, envp);
		if (ast)
			ft_free_ast(ast);
		fd = open("/tmp/heredoc", O_RDONLY | O_CREAT | O_TRUNC, 0777);
		close(fd);
	}
	if (token_list)
		ft_free_token_list(token_list);
}

void	ft_handle_signal_main(int sg)
{
	if (sg == 2)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_code = 130;
	}
	if (sg == 3)
	{
		write(1, "\b\b  \b\b", 6);
		return ;
	}
}

void	ft_minishell_loop(t_hashtable **env_ht, char **input, char **envp)
{
	char		*prompt;

	prompt = "\033[0;33m|( o)═( o)|\033[0;m >";
	while (1)
	{
		signal(SIGINT, &ft_handle_signal_main);
		signal(SIGQUIT, &ft_handle_signal_main);
		*input = readline(prompt);
		if (!*input)
		{
			printf("exit\n");
			if (env_ht)
				ft_free_hashtable(*env_ht);
			exit(0);
		}
		if (ft_strlen(*input) == 0)
		{
			free(*input);
			continue ;
		}
		add_history(*input);
		ft_handle_input(*input, env_ht, envp);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_hashtable	*env_ht;
	char		*input;

	(void)argc;
	(void)argv;
	env_ht = ft_create_env_hashtable(env);
	printf("\n");
	ft_print_title();
	input = NULL;
	ft_minishell_loop(&env_ht, &input, env);
	if (env_ht)
		ft_free_hashtable(env_ht);
	return (0);
}
