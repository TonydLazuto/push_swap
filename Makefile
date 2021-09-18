.PHONY		= all clean fclean re bonus bonusclean bonusfclean libclean libfclean

NAME		= push_swap

CHECKER		= checker

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= /bin/rm -f

LIB_DIR		= libft

OBJ_DIR		= obj

LIBA		= $(LIB_DIR)/libft.a

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

OBJS		= $(SRCS:.c=.o)

DIR_OBJS	= $(addprefix $(OBJ_DIR)/,$(OBJS))

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

DIR_OBJS_B	= $(addprefix $(BONUS_DIR)/,$(OBJS_BONUS))

all: 			$(NAME)

$(NAME): 		$(DIR_OBJS)
				@make --silent -C $(LIB_DIR)	
				$(CC) $(CFLAGS) $(LIBA) -o $(NAME) $(DIR_OBJS) -L$(LIB_DIR) -lft

bonus:			$(DIR_OBJS_B)
				@make --silent -C $(LIB_DIR)	
				$(CC) $(CFLAGS) $(LIBA) -o $(CHECKER) $(DIR_OBJS_B) -L$(LIB_DIR) -lft

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
				$(RM) $(LIBA)
				$(RM) $(NAME)

bonusclean:		libclean
				$(RM) $(DIR_OBJS_B)

bonusfclean:	bonusclean
				$(RM) $(LIBA)
				$(RM) $(CHECKER)
				

re:				fclean all
