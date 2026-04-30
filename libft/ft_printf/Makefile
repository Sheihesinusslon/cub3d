NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
       ft_vfprintf.c \
       ft_puts.c \
       ft_putchar.c \
       print_utils.c \
       handle_char.c \
       handle_string.c \
       handle_pointer.c \
       handle_integer.c \
       handle_decimal.c \
       handle_unsigned.c \
       handle_hexadecimal.c \
       handle_hexadecimal_upper.c \
       handle_percent.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h

.PHONY: all run clean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
