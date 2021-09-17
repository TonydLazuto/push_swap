.PHONY		= all clean fclean re bonus bonusclean bonusfclean libclean libfclean

NAME		= push_swap

CHECKER		= checker

LIBA		= libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= /bin/rm -f

INC			= push_swap.h

LIB_DIR		= libft

OBJ_DIR		= obj

BONUS_DIR	= bonus

SRCS		= push_swap.c \
			  extras.c \
			  check_args.c \
			  lst_nb.c \
			  lst_nb2.c \
			  exec_ins.c \
			  exec_ins2.c \
			  exit.c \
			  rolls.c \
			  chunk.c \
			  chunk_utils.c \
			  utils.c

SRCS_BONUS	=	exec_ins2.c \
				exec_ins.c \
				ft_error.c \
				ft_exit.c \
				get_next_line.c \
				get_next_line_utils.c \
				lst_ins.c \
				lst_nb2.c \
				lst_nb.c \
				main.c \
				stack_ins.c \
				stack_nb.c

OBJS		= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

OBJS_BONUS	= $(addprefix $(BONUS_DIR)/,$(SRCS_BONUS:.c=.o))

all: 			$(NAME)

$(NAME): 		$(OBJS)
				@make --silent -C $(LIB_DIR)	
				$(CC) $(CFLAGS) $(LIB_DIR)/libft.a -o $(NAME) $(OBJS) -L$(LIB_DIR) -lft

bonus:			$(OBJS_BONUS) $(LIB)
				$(CC) $(CFLAGS) -o $(CHECKER) $(OBJS_BONUS) -L$(LIB_DIR) -lft

$(OBJ_DIR)/%.o:	%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

libclean:		
				@make clean -C $(LIB_DIR)

libfclean:
				@make fclean -C $(LIB_DIR)

clean:			libclean
				rm -rf $(OBJ_DIR)

fclean:			clean
				$(RM) $(LIB_DIR)/libft.a
				$(RM) $(NAME)

bonusclean:		libclean
				$(RM) $(OBJS_BONUS)

bonusfclean:	bonusclean
				$(RM) $(LIB_DIR)/libft.a
				$(RM) $(CHECKER)
				

re:				fclean all
