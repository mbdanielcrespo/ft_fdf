NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra


SRC = src/main.c \
src/read_file.c

OBJ = $(SRC:.c =.o)

LIBFT = libft/ft_libft.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./libft -lft

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) 

clean:
	cd libft && make clean
	rm -f &(OBJ)

fclean:
	cd libft && make fclean
	rm -f &(NAME)

re: fclean all

.PHONY: all clean fclean re