CHECK_NAME	=	checker
PS_NAME		=	push_swap

CHECK_SRCS	=	checker.c		\
				checker2.c		\
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
				big_sorting2.c	\
				GNL/get_next_line.c		\
				GNL/get_next_line_utils.c	\

CHECK_OBJS	= $(CHECK_SRCS:%.c=%.o)

PS_SRCS		=	pushswap.c		\
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


PS_OBJS	=	$(PS_SRCS:%.c=%.o)

CFLAGS	=	-Wall -Werror -Wextra -g3

CC		=	gcc

all : $(PS_NAME) $(CHECK_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


$(PS_NAME): $(PS_OBJS)
	$(CC) $(CFLAGS) $(PS_OBJS) -o $(PS_NAME)
	@echo "##### push_swap compiling finished! #####"

$(CHECK_NAME): $(CHECK_OBJS)
	$(CC) $(CFLAGS) $(CHECK_OBJS) -o $(CHECK_NAME)
	@echo "##### checker compiling finished! #####"

clean :
	rm -rf $(PS_OBJS)
	rm -rf $(CHECK_OBJS)

fclean : clean
	rm -f $(PS_NAME)
	rm -f $(CHECK_NAME)

re : fclean all

.PHONY : all clean fclean re
