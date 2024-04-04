NAME	= push_swap


src = 	./main.c \
		./error.c \
		./ft_push.c \
		./ft_swap.c \
		./ft_rotate.c \
		./ft_reverse_rotate.c \
		./cost_analisis.c \
		./sort_stack.c \
		./stack_utils.c \
		./stack.c \

OBJS 	= $(src:.c=.o)

HEADER	= includes

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

LIB = libft/libft.a

.c.o:		%.o : %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
	make -C ./libft
	$(CC) $(OBJS) -Llibft -lft -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: 	clean
	make fclean -C ./libft
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re