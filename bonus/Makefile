.PHONY		= all clean fclean re bonus

NAME		= checker

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -O3 -g3 -fsanitize=address

RM			= /bin/rm -f

INC			= checker.h

LIB_DIR		= ./../libft

OBJ_DIR		= obj

SRCS		= main.c \
			  stack_ins.c \
			  stack_nb.c \
			  lst_ins.c \
			  lst_nb.c \
			  lst_nb2.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  ft_exit.c \
			  ft_error.c \
			  exec_ins.c \
			  exec_ins2.c

OBJS		= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: 			$(NAME)

$(NAME): 		$(OBJS) $(INC)
				@ make --silent -C $(LIB_DIR)
				$(CC) $(FLAGS) $(LIB_DIR)/libft.a -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:	%.c
				@ $(shell mkdir -p $(OBJ_DIR))
				$(CC) $(FLAGS) -c $< -o $@

clean:
				@ make clean -C $(LIB_DIR)
				rm -rf $(OBJ_DIR)

fclean:			clean
				$(RM) $(LIB_DIR)/libft.a
				$(RM) $(NAME)

re:				fclean all
