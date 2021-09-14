.PHONY		= all clean fclean re bonus

NAME		= push_swap

CHECKER		= checker

LIB			= libft.a

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

$(LIB):
				$(MAKE) --silent -C $(LIB_DIR)

$(NAME): 		$(OBJS) $(LIB)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_DIR) -lft

bonus:			$(OBJS) $(OBJS_BONUS) $(LIB)
				$(CC) $(CFLAGS) -o $(CHECKER) $(OBJS_BONUS) -L$(LIB_DIR) -lft

$(OBJ_DIR)/%.o:	%.c
				@ $(shell mkdir -p $(OBJ_DIR))
				$(CC) $(CFLAGS) -c $< -o $@

libclean:		
				$(MAKE) clean -C $(LIB_DIR)

libfclean:		libclean
				$(RM) $(LIB_DIR)/$(LIB)

clean:			libclean
				rm -rf $(OBJ_DIR)

fclean:			clean
				$(RM) $(LIB_DIR)/libft.a
				$(RM) $(NAME)

bonusclean:		clean
				$(RM) $(OBJS_BONUS)

bonusfclean:	bonusclean fclean
				$(RM) $(CHECKER)
				

re:				fclean all
