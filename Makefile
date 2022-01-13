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
			lexer/ft_lexer.c \
			lexer/ft_token_list.c \
			lexer/ft_get_token_len.c \

INCS		=	minishell.h \
			lexer.h \

# **************************************************************************** #
#       LIBRARIES                                                              #
# **************************************************************************** #

# **************************************************************************** #
#       RULES                                                                  #
# **************************************************************************** #
OBJS		=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

%.o		:	%.c
			$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

$(NAME)		:	$(OBJS)
			$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(READLINE)

all		:	$(NAME)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

# **************************************************************************** #
#       PHONY                                                                  #
# **************************************************************************** #
.PHONY		:	all bonus clean fclean re
