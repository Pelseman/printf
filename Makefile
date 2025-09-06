NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
COMPILE = cc $(CFLAGS) -c
REMOVE = rm -f

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(COMPILE) $<

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
