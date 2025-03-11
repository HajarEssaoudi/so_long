NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./src/main.c ./src/check_errors.c ./src/check_map_validity.c
OBJS = $(SRCS:.c=.o)

LIB1 = ./include/libft/libft.a
LIB2 = ./include/ft_printf/libftprintf.a

do: all clean

all: $(NAME)

$(NAME): $(LIB1) $(LIB2) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB1) $(LIB2) -o $(NAME)

$(LIB1):
	make -C ./include/libft

$(LIB2):
	make -C ./include/ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ./include/libft clean
	make -C ./include/ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ./include/libft fclean
	make -C ./include/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re