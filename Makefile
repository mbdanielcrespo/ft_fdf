NAME = fdf
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

MLX = minilibx-linux/libmlx.a
MLX_FLAGS = -Lminilibx-linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC = src/main.c \
src/read_file.c \
src/draw.c \
src/utils.c

OBJ = $(SRC:.c =.o)

LIBFT = libft/ft_libft.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./libft -lft $(MLX) $(MLX_FLAGS)

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) 

clean:
	make clean -C ./libft
	make clean -C ./minilibx-linux
	$(RM) $(OBJ)

fclean:
	make fclean -C ./libft
	make clean -C ./minilibx-linux
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re