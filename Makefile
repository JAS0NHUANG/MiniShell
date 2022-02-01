# **************************************************************************** #
#       COMANDS                                                                #
# **************************************************************************** #
CC			=	gcc
RM			=	rm -rf
AR			=	ar rcs

# **************************************************************************** #
#       TITLE                                                                  #
# **************************************************************************** #
NAME		=	minishell

# **************************************************************************** #
#       FLAGS                                                                  #
# **************************************************************************** #
CFLAGS		=	-Wall -Wextra -Werror
READLINE	=	-lreadline
TERMCAP		=	-ltermcap
FSAN		=	-fsanitize=address
DEBUG		=	-g3

# **************************************************************************** #
#       SOURCES                                                                #
# **************************************************************************** #
SRCS_DIR	=	srcs
INCS_DIR	=	incs

SRCS		=	minishell.c \
				utils/ft_check_syntax_error.c \
				utils/ft_print_title.c \
				hashtable/ft_create_hashtable.c \
				hashtable/ft_create_element.c \
				hashtable/ft_add_element.c \
				hashtable/ft_delete_element.c \
				hashtable/ft_get_value.c \
				hashtable/ft_ch_value.c \
				hashtable/ft_monkey_hash.c \
				hashtable/ft_free_hashtable.c \
				env/ft_create_env_hashtable.c \
				env/ft_print_env.c \
				lexer/ft_lexer.c \
				lexer/ft_token_list.c \
				lexer/ft_get_token_len.c \
				lexer/ft_check_token.c \
				lexer/ft_expansion.c \
				lexer/ft_substitution.c \
				lexer/ft_expand_token_list.c \
				parser/ft_parser.c \
				parser/ft_add_redir_node.c \
				parser/ft_free_ast.c \
				builtins/ft_export.c \
				builtins/ft_env.c \
				builtins/ft_unset.c \
				builtins/ft_cd.c \
				builtins/ft_echo.c \
				builtins/ft_exit.c \
				builtins/ft_pwd.c \
				execution/ft_pipe.c \
				execution/ft_execute_node.c \
				execution/ft_run_single_cmd.c \
				execution/ft_execve_cmd.c \
				execution/ft_execute_builtin.c \
				redirection/ft_handle_heredoc.c \
				redirection/ft_handle_redir.c \

INCS		=	minishell.h \

# **************************************************************************** #
#       LIBRARIES                                                              #
# **************************************************************************** #
LIBFT_A			=	libft.a
LIBFT_DIR		=	libft

# **************************************************************************** #
#       RULES                                                                  #
# **************************************************************************** #
OBJS		=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

%.o			:	%.c
			$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

$(NAME)		:	$(OBJS) $(LIBFT_A)
			$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(READLINE) $(CFLAGS)

$(LIBFT_A)		:
					make -C $(LIBFT_DIR) $(LIBFT_FLAGS) $(CFLAGS)
					mv $(LIBFT_DIR)/$(LIBFT_A) .

all			:	$(NAME)

leak_check	:	$(OBJS) $(LIBFT_A)
			$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(READLINE) $(FSAN)

clean		:
			$(RM) $(OBJS) $(LIBFT_A)
			make clean -C $(LIBFT_DIR)

fclean		:	clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT_DIR)

re			:	fclean all

# **************************************************************************** #
#       PHONY                                                                  #
# **************************************************************************** #
.PHONY		:	all bonus clean fclean re

