NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INC_PATH = printf.h

SRC_NAME = ft_printf.c is_flag.c is_hex.c is_put.c is_lib.c

OBJ_NAME = $(SRC_NAME:.c=.o)

$(NAME): $(OBJ_NAME)
		ar rcs ${NAME} ${OBJ_NAME}

%.o: %.c $(INC_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf $(OBJ_NAME)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
