NAME = so_long
CC = gcc
CFLAGS =

SRC_PATH = src
OBJ_PATH = obj

SRC_NAME = main.c check_errors_emptiness.c check_errors_flags.c check_errors_rectangulaire.c	\
			check_errors_walls.c check_map_utils.c check_map_validity.c gnl/get_next_line.c		\
			gnl/get_next_line_utils.c check_errors_map_elements.c check_map_accessibility.c render_map.c moves.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRCS = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

LIB1 = ./include/libft/libft.a
LIB2 = ./include/ft_printf/libftprintf.a
MLX = -Lmlx_linux -lmlx_Linux -L/usr/include/minilibx-linux -lXext -lX11

do: all clean

all: $(NAME)

$(NAME): $(LIB1) $(LIB2) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB1) $(LIB2) $(MLX) -o $(NAME) -I include -g
	@echo "✅ Build successful!"

$(LIB1):
	make -C ./include/libft

$(LIB2):
	make -C ./include/ft_printf

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJS))
	@$(CC) $(CFLAGS) -c $< -o $@ -I include -g
	@echo $<

clean:
	rm -f $(OBJS)
	make -C ./include/libft fclean
	make -C ./include/ft_printf fclean
	rm -rf obj
	@echo "✅ deleted successful!"

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
