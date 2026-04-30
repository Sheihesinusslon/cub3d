NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line.c
	
SRCS_LL = ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c

OBJS = $(SRCS:.c=.o)
LL_OBJS = $(SRCS_LL:.c=.o)
OBJS += $(LL_OBJS)


INCLUDE = libft.h
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_TMP_DIR = .ft_printf_objs


all: $(FT_PRINTF_LIB) $(NAME)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS) $(FT_PRINTF_LIB)
	@mkdir -p $(FT_PRINTF_TMP_DIR)
	@cp $(FT_PRINTF_LIB) $(FT_PRINTF_TMP_DIR)/tmp.a
	@cd $(FT_PRINTF_TMP_DIR) && ar x tmp.a
	@ar rcs $@ $? 
	@ar rcs $@ $(FT_PRINTF_TMP_DIR)/*.o
	@rm -rf $(FT_PRINTF_TMP_DIR)

%.o: %.c $(INCLUDE) Makefile
	$(CC) $(CFLAGS) -I. -I$(FT_PRINTF_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(FT_PRINTF_TMP_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	

re: fclean all

.PHONY: all bonus clean fclean re
