/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:58 by antton-t          #+#    #+#             */
/*   Updated: 2022/01/31 04:43:56 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int	g_exit_code;

void	ft_handle_input(char *input, t_hashtable **env_ht)
{
	t_token	*token_list;
	t_ast	*ast;

	token_list = ft_lexer(input);
	ft_expand_token_list(&token_list, *env_ht);
	ast = ft_create_ast(token_list);
	if (!ast->left && !ast->right)
		ft_run_single_cmd(ast, env_ht, token_list);
	else
		ft_handle_pipe(ast, *env_ht);
	if (ast)
		ft_free_ast(ast);
	if (token_list)
		ft_free_token_list(token_list);
}

void	ft_minishell_loop(char *prompt, t_hashtable **env_ht, char **input)
{
	while (1)
	{
		*input = readline(prompt);
		if (!*input)
		{
			printf("exit\n");
			if (*env_ht)
				ft_free_hashtable(*env_ht);
			exit(0);
		}
		if (ft_strlen(*input) == 0)
		{
			free(*input);
			continue ;
		}
		add_history(*input);
		ft_handle_input(*input, env_ht);
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
	t_hashtable	*env_ht;
	char		*input;

	(void)argc;
	(void)argv;
	env_ht = ft_create_env_hashtable(env);
	printf("\n");
	prompt = "|( o)═( o)| >";
	ft_print_title();
	input = NULL;
	ft_minishell_loop(prompt, &env_ht, &input);
	if (env_ht)
		ft_free_hashtable(env_ht);
	return (0);
}
