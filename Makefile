NAME=cub3d
CC=gcc
HEADER=./include/
CFLAGS=-Wall -Werror -Wextra -I $(HEADER)
MLXFLAG = -L./minilibx-linux -lmlx - framework OpenGL -framework AppKit

SRCS = main.c

MLX = ./minilibx-linux
OBJS=$(SRCS:.c=.o)


$(NAME):$(OBJS) $(MLX) $(HEADER)
	$(CC) $(CFLAGS) $(MLXFLAG) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(MLX)
	

fclean: clean
	rm -rf $(NAME)
re: make fclean
	make all

.PHONY: all clean fclean re