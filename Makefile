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
				hashtable/ft_create_hashtable.c \
				hashtable/ft_create_element.c \
				hashtable/ft_get_value.c \
				hashtable/ft_monkey_hash.c \
				hashtable/ft_free_hashtable.c \
				builtins/ft_pwd.c \
				builtins/ft_echo.c \
				builtins/ft_cd.c \
				builtins/ft_env.c \
				builtins/ft_execve.c \
				builtins/ft_exit.c \
				builtins/ft_export.c \
				env/ft_create_env_hashtable.c \
				lexer/ft_lexer.c \
				lexer/ft_token_list.c \
				lexer/ft_get_token_len.c \
				lexer/ft_check_quote.c \
				parser/ft_parser.c \
				parser/ft_add_redir_node.c \
				parser/ft_free_ast.c \
				pipe/ft_pipe.c \
				pipe/ft_tools_pipe.c \

INCS		=	minishell.h \
				hashtable.h \
				lexer.h \
				utils.h \

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
			$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(READLINE)

$(LIBFT_A)		:
					make -C $(LIBFT_DIR) $(LIBFT_FLAGS)
					mv $(LIBFT_DIR)/$(LIBFT_A) .

all			:	$(NAME)

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
