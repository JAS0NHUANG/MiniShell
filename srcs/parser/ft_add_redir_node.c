/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_redir_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:36:40 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/31 12:16:40 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*ft_init_redir_node(int token_type)
{
	t_redir	*redir_node;

	redir_node = malloc(sizeof(t_redir));
	redir_node->value = NULL;
	redir_node->next = NULL;
	if (token_type == TOKEN_GREATER)
		redir_node->redir_type = REDIR_OUT;
	else if (token_type == TOKEN_GREATGREATER)
		redir_node->redir_type = REDIR_APPEND_OUT;
	else if (token_type == TOKEN_LESSER)
		redir_node->redir_type = REDIR_IN;
	else if (token_type == TOKEN_LESSLESSER)
		redir_node->redir_type = REDIR_HEREDOC;
	return (redir_node);
}

t_redir	*ft_add_redir_node(t_redir *redir_list, t_token *token_list)
{
	t_redir	*redir_node;
	t_redir	*redir_list_holder;
	int		token_type;

	token_type = token_list->token_type;
	token_list = token_list->next;
	if (!token_list)
		return (NULL);
	redir_node = ft_init_redir_node(token_type);
	redir_node->value = ft_strdup(token_list->value);
	if (!redir_list)
		return (redir_node);
	redir_list_holder = redir_list;
	while (redir_list->next)
		redir_list = redir_list->next;
	redir_list->next = redir_node;
	redir_list = redir_list_holder;
	return (redir_list);
}
