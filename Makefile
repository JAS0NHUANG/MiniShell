# **************************************************************************** #
#       COMANDS                                                                #
# **************************************************************************** #
CC		=	gcc
RM		=	rm -rf
AR		=	ar rcs

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
			lexer/ft_parsing_dollar.c \
			lexer/ft_parsing_single_quote.c \
			lexer/ft_lexer.c \
			lexer/ft_create_env_hashtable.c \
			utils/ft_is_prime.c \
			utils/ft_next_prime.c \
			utils/ft_strjoin.c \
			utils/ft_strlen.c \
			utils/ft_arraylen.c \
			hashtable/ft_create_hashtable.c \

INCS		=	minishell.h \
			hashtable.h \
			lexer.h \

# **************************************************************************** #
#       LIBRARIES                                                              #
# **************************************************************************** #

# **************************************************************************** #
#       RULES                                                                  #
# **************************************************************************** #
OBJS		=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

%.o			:	%.c
				$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

$(NAME)		:	$(OBJS)
				$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(READLINE)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

# **************************************************************************** #
#       PHONY                                                                  #
# **************************************************************************** #
.PHONY		:	all bonus clean fclean re
