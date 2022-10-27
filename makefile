CHECK_NAME	=	checker
PS_NAME		=	push_swap

CHECK_SRCS	=	bonus_check/checker.c		\
				bonus_check/checker2.c		\
				bonus_check/checker3.c		\
				Srcs/ps_commands.c	\
				Srcs/ps_commands2.c	\
				Srcs/ps_utils.c		\
				Srcs/ps_utils2.c		\
				Srcs/stack.c			\
				Srcs/check.c			\
				Srcs/error_check.c	\
				Srcs/tri_triple.c	\
				Srcs/sorting.c		\
				Srcs/big_sorting.c	\
				Srcs/big_sorting2.c	\
				GNL/get_next_line.c		\
				GNL/get_next_line_utils.c	\

CHECK_OBJS	= $(CHECK_SRCS:%.c=%.o)

PS_SRCS		=	Srcs/pushswap.c		\
				Srcs/ps_commands.c	\
				Srcs/ps_commands2.c	\
				Srcs/ps_utils.c		\
				Srcs/ps_utils2.c		\
				Srcs/stack.c			\
				Srcs/check.c			\
				Srcs/error_check.c	\
				Srcs/tri_triple.c	\
				Srcs/sorting.c		\
				Srcs/big_sorting.c	\
				Srcs/big_sorting2.c

GREEN	=	\033[1;32m
DEFAULT	=	\033[0m

PS_OBJS	=	$(PS_SRCS:%.c=%.o)

CFLAGS	=	-Wall -Werror -Wextra

CC		=	gcc

all : $(PS_NAME) $(CHECK_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PS_NAME): $(PS_OBJS)
	$(CC) $(CFLAGS) $(PS_OBJS) -o $(PS_NAME)
	@echo "$(GREEN)##### push_swap compiling finished! #####$(DEFAULT)"

bonus : $(CHECK_NAME)

$(CHECK_NAME): $(CHECK_OBJS)
	$(CC) $(CFLAGS) $(CHECK_OBJS) -o $(CHECK_NAME)
	@echo "$(GREEN)##### checker compiling finished! #####$(DEFAULT)"

clean :
	rm -rf $(PS_OBJS)
	rm -rf $(CHECK_OBJS)

fclean : clean
	rm -f $(PS_NAME)
	rm -f $(CHECK_NAME)

re : fclean all

.PHONY : all clean fclean re
