/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <jahuang@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:00:59 by jahuang           #+#    #+#             */
/*   Updated: 2022/01/26 17:30:34 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_element(t_token *token_list)
{
	int		count;
	t_token	*ptr;

	ptr = token_list;
	count = 0;
	if (ptr->token_type == TOKEN_PIPE)
		count++;
	while (ptr && ptr->token_type != TOKEN_PIPE)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

t_ast	*ft_malloc_node(int nb_element)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->value = calloc(nb_element + 1, sizeof(char **));
	node->redir_list = NULL;
	return (node);
}

int	ft_is_redir(int token_type)
{
	if (token_type == TOKEN_GREATER || token_type == TOKEN_GREATGREATER || \
		token_type == TOKEN_LESSER || token_type == TOKEN_LESSLESSER)
		return (1);
	return (0);
}

t_ast	*ft_create_ast_node(t_token *token_list, int nb_element)
{
	t_ast	*node;
	int		index;

	index = 0;
	node = ft_malloc_node(nb_element);
	if (token_list->token_type == TOKEN_PIPE)
		node->node_type = NODE_PIPE;
//	else
//		node->node_type = NODE_CMD;
	while (nb_element--)
	{
		if (ft_is_redir(token_list->token_type) == 1)
		{
			node->node_type = NODE_LIST;
			node->redir_list = ft_add_redir_node(node->redir_list, token_list);
			token_list = token_list->next;
			nb_element--;
		}
		else
		{
			node->value[index] = ft_strdup(token_list->value);
			index++;
		}
		token_list = token_list->next;
	}
	return (node);
}

t_ast	*ft_create_ast(t_token *token_list)
{
	t_ast	*ast_tree;
	t_ast	*node_holder;
	int		nb_element;

	ast_tree = NULL;
	node_holder = NULL;
	nb_element = 0;
	while (token_list)
	{
		nb_element = ft_count_element(token_list);
		node_holder = ft_create_ast_node(token_list, nb_element);
		if (!ast_tree)
			ast_tree = node_holder;
		else if (token_list->token_type == TOKEN_PIPE)
		{
			node_holder->left = ast_tree;
			ast_tree = node_holder;
		}
		else
			ast_tree->right = node_holder;
		while (nb_element--)
			token_list = token_list->next;
		node_holder = NULL;
	}
	return (ast_tree);
}
