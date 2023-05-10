NAME=cub3D
CC=cc
HEADER=./include/
CFLAGS=-Wall -Werror -Wextra -I $(HEADER)
MLXFLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

SRCS = main.c \
	get_next_line.c \
	get_next_line_utils.c \
	texture.c \
	utils1.c \
	utils2.c \
	floor_ceiling.c \
	map_check.c \
	mapping.c \
	free.c
	dda.c \
	draw.c \
	init.c \
	keyhook.c \
	minimap.c \
	window.c	\


MLX = ./mlx
LIB = ./libft
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(MLX) $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) $(MLXFLAG) $(LIBFT) $(OBJS) -o $(NAME)
#$(NAME):$(OBJS) $(LIBFT) $(HEADER)
#	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  -o $(NAME)

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
