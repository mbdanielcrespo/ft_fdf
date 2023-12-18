NAME = fdf
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address
INC_FLAGS = -I ./inc/ -I .minilibx-linux/ -I ./libft/

MLX = .minilibx-linux/libmlx.a
MLX_FLAGS = -L.minilibx-linux -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm #-lz

SRC = src/main.c \
src/read_file.c \
src/draw.c \
src/god.c \
src/setters.c \
src/projections.c

LIBFT = libft/libft.a

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(INC_FLAGS) $(SRC) -o $(NAME) -L./libft -lft $(MLX) $(MLX_FLAGS)
 
$(LIBFT):
	make -C libft

$(MLX):
	make -C .minilibx-linux

all: $(NAME) 

clean:
	@make clean -C ./libft
	@$(RM) $(OBJ)

fclean:
	@make fclean -C ./libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re