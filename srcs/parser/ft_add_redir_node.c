/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_redir_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:36:40 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/26 13:36:13 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*ft_init_redir_node(int token_type)
{
	t_redir	*redir_node;

	redir_node = malloc(sizeof(t_redir));
	redir_node->value = NULL;
	redir_node->next = NULL;
	redir_node->fd_heredoc = -1;
	if (token_type == TOKEN_GREATER)
		redir_node->redir_type = REDIR_OUT;
	if (token_type == TOKEN_GREATGREATER)
		redir_node->redir_type = REDIR_APPEND_OUT;
	if (token_type == TOKEN_LESSER)
		redir_node->redir_type = REDIR_IN;
	if (token_type == TOKEN_LESSLESSER)
		redir_node->redir_type = REDIR_HEREDOC;
	return (redir_node);
}

t_redir	*ft_add_redir_node(t_redir *redir_list, t_token *token_list)
{
	t_token	*ptr;
	t_redir	*redir_node;
	t_redir	*redir_list_holder;

	ptr = token_list;
	redir_node = ft_init_redir_node(ptr->token_type);
	ptr = ptr->next;
	redir_node->value = ft_strdup(ptr->value);
	if (token_list->fd != -1)
		redir_node->fd_heredoc = token_list->fd;
	if (!redir_list)
		return (redir_node);
	redir_list_holder = redir_list;
	while (redir_list->next)
		redir_list = redir_list->next;
	redir_list->next = redir_node;
	redir_list = redir_list_holder;
	return (redir_list);
}
