.PHONY		= all clean fclean re bonus

NAME		= bonus_push_swap

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -O3 -g3 -fsanitize=address

RM			= /bin/rm -f

INC			= checker.h

LIB_DIR		= libft

OBJ_DIR		= obj

SRCS		= checker.c \
			  checker2.c \
			  ins_lst.c \
			  nb_lst.c \
			  get_next_line.c \
			  get_next_line_utils.c \
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
