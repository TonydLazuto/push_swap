.PHONY		= all clean fclean re bonus

NAME		= push_swap

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -O3 -g3 -fsanitize=address

RM			= /bin/rm -f

INC			= push_swap.h

LIB_DIR		= libft

OBJ_DIR		= obj

SRCS		= push_swap.c \
			  extras.c \
			  utils.c \
			  exit.c

OBJS		= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: 			$(NAME)

$(NAME): 		$(OBJS) $(INC)
				@ make --silent -C $(LIB_DIR)
				$(CC) $(FLAGS) $(LIB_DIR)/libft.a -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:	%.c
				@ $(shell mkdir -p $(OBJ_DIR))
				$(CC) $(FLAGS) -c $< -o $@

clean:
				@ make clean -C libft
				rm -rf $(OBJ_DIR)

fclean:			clean
				$(RM) $(LIB_DIR)/libft.a
				$(RM) $(NAME)

re:				fclean all
