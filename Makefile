NAME = fdf
CC = CC
CFLAGS = -Wall -Werror -Wextra

SRC = src/main.c \
src/read_file.c

OBJ = $(SRC:.c = .0)

LIBFT = libft/ft_

all:

