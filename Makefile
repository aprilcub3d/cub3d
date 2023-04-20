NAME=cub3d
CC=gcc
HEADER=./include/
CFLAGS=-Wall -Werror -Wextra -I $(HEADER)
MLXFLAG = -L./minilibx-linux -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

SRCS = main.c \
	get_next_line.c \
	get_next_line_utils.c \
	texture.c \
	utils1.c \
	floor_ceiling.c \
	map_check.c

MLX = ./minilibx-linux
LIB = ./libft
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(MLX) $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) $(MLXFLAG) $(LIBFT) $(OBJS) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	make clean -C $(LIB)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB)

re:
	make fclean
	make all

.PHONY: all clean fclean re
