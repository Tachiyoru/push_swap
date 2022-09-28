NAME	=	push_swap

SRCS	=	pushswap.c		\
			ps_commands.c	\
			ps_commands2.c	\
			ps_utils.c		\
			ps_utils2.c		\
			stack.c			\
			check.c			\
			error_check.c	\
			tri_triple.c	\
			sorting.c		\
			big_sorting.c	\
			big_sorting2.c


OBJS	=	$(SRCS:%.c=%.o)

CFLAGS	=	-Wall -Werror -Wextra -g3

CC		=	gcc

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
