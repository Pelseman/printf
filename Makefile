NAME    = libftprintf.a
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f
SRC = \
	ft_printf.c \
	ft_putchar.c \
	ft_puthexl.c \
	ft_puthexu.c \
	ft_putnbr.c \
	ft_putptr.c \
	ft_putstr.c \
	ft_putunbr.c
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c ft_printf.h
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

