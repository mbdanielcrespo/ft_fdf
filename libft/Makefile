CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = ft_atoi.c ft_isascii.c ft_memcmp.c ft_putchar_fd.c ft_putstr_fd.c \
            ft_striteri.c ft_strmapi.c ft_substr.c ft_bzero.c ft_isdigit.c \
            ft_memcpy.c ft_putchar_fdp.c ft_putstr_fdp.c ft_strjoin.c ft_strncmp.c \
            ft_tolower.c ft_calloc.c ft_isprint.c ft_memmove.c ft_putendl_fd.c \
            ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_isalnum.c \
            ft_itoa.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strlcpy.c \
            ft_strrchr.c ft_isalpha.c ft_memchr.c ft_pow.c ft_putnbr_fdp.c \
            ft_strdup.c ft_strlen.c ft_strtrim.c ft_printf.c ft_printf_ptr.c \
            ft_swap.c get_next_line.c get_next_line_utils.c ft_error.c

OBJ_FILES = $(SRC_FILES:.c=.o)

OUTPUT_LIB = libft.a

all: $(OUTPUT_LIB)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT_LIB): $(OBJ_FILES)
	ar rcs $(OUTPUT_LIB) $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(OUTPUT_LIB)

re: fclean all

.PHONY: all clean fclean re
