NAME = fdf
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

MLX = minilibx-linux/libmlx.a
MLX_FLAGS = -Lminilibx-linux -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC = src/main.c \
src/read_file.c \
src/draw.c

OBJ = $(SRC:.c =.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

LIBFT = libft/ft_libft.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./libft -lft $(MLX) $(MLX_FLAGS)

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx-linux

all: $(NAME) 

clean:
	@make clean -C ./libft
	@$(RM) $(OBJ)

fclean:
	@make fclean -C ./libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re