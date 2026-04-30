NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I$(LIBFT_DIR) -I$(MLX_DIR)
SRCS = \
	main.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
HEADERS = cub3d.h

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_SRCS = \
	$(LIBFT_DIR)/ft_atoi.c \
	$(LIBFT_DIR)/ft_bzero.c \
	$(LIBFT_DIR)/ft_calloc.c \
	$(LIBFT_DIR)/ft_isalnum.c \
	$(LIBFT_DIR)/ft_isalpha.c \
	$(LIBFT_DIR)/ft_isascii.c \
	$(LIBFT_DIR)/ft_isdigit.c \
	$(LIBFT_DIR)/ft_isprint.c \
	$(LIBFT_DIR)/ft_itoa.c \
	$(LIBFT_DIR)/ft_memchr.c \
	$(LIBFT_DIR)/ft_memcmp.c \
	$(LIBFT_DIR)/ft_memcpy.c \
	$(LIBFT_DIR)/ft_memmove.c \
	$(LIBFT_DIR)/ft_memset.c \
	$(LIBFT_DIR)/ft_putchar_fd.c \
	$(LIBFT_DIR)/ft_putendl_fd.c \
	$(LIBFT_DIR)/ft_putnbr_fd.c \
	$(LIBFT_DIR)/ft_putstr_fd.c \
	$(LIBFT_DIR)/ft_split.c \
	$(LIBFT_DIR)/ft_strchr.c \
	$(LIBFT_DIR)/ft_strdup.c \
	$(LIBFT_DIR)/ft_striteri.c \
	$(LIBFT_DIR)/ft_strjoin.c \
	$(LIBFT_DIR)/ft_strlcat.c \
	$(LIBFT_DIR)/ft_strlcpy.c \
	$(LIBFT_DIR)/ft_strlen.c \
	$(LIBFT_DIR)/ft_strmapi.c \
	$(LIBFT_DIR)/ft_strncmp.c \
	$(LIBFT_DIR)/ft_strnstr.c \
	$(LIBFT_DIR)/ft_strrchr.c \
	$(LIBFT_DIR)/ft_strtrim.c \
	$(LIBFT_DIR)/ft_substr.c \
	$(LIBFT_DIR)/ft_tolower.c \
	$(LIBFT_DIR)/ft_toupper.c \
	$(LIBFT_DIR)/get_next_line.c \
	$(LIBFT_DIR)/ft_lstadd_back.c \
	$(LIBFT_DIR)/ft_lstadd_front.c \
	$(LIBFT_DIR)/ft_lstclear.c \
	$(LIBFT_DIR)/ft_lstdelone.c \
	$(LIBFT_DIR)/ft_lstiter.c \
	$(LIBFT_DIR)/ft_lstlast.c \
	$(LIBFT_DIR)/ft_lstmap.c \
	$(LIBFT_DIR)/ft_lstnew.c \
	$(LIBFT_DIR)/ft_lstsize.c

LIBFT_HEADERS = $(LIBFT_DIR)/libft.h $(LIBFT_DIR)/ft_printf/ft_printf.h

FT_PRINTF_DIR = $(LIBFT_DIR)/ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_SRCS = \
	$(LIBFT_DIR)/ft_printf/ft_printf.c \
        $(LIBFT_DIR)/ft_printf/ft_vfprintf.c \
        $(LIBFT_DIR)/ft_printf/ft_puts.c \
        $(LIBFT_DIR)/ft_printf/ft_putchar.c \
        $(LIBFT_DIR)/ft_printf/print_utils.c \
        $(LIBFT_DIR)/ft_printf/handle_char.c \
        $(LIBFT_DIR)/ft_printf/handle_string.c \
        $(LIBFT_DIR)/ft_printf/handle_pointer.c \
        $(LIBFT_DIR)/ft_printf/handle_integer.c \
        $(LIBFT_DIR)/ft_printf/handle_decimal.c \
        $(LIBFT_DIR)/ft_printf/handle_unsigned.c \
        $(LIBFT_DIR)/ft_printf/handle_hexadecimal.c \
        $(LIBFT_DIR)/ft_printf/handle_hexadecimal_upper.c \
        $(LIBFT_DIR)/ft_printf/handle_percent.c

all: $(MLX_LIB) $(LIBFT) $(NAME)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

$(FT_PRINTF_LIB): $(FT_PRINTF_SRCS)
	@$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory

$(LIBFT): $(LIBFT_SRCS) $(FT_PRINTF_SRCS) $(LIBFT_HEADERS)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(OBJS) Makefile | $(MLX_LIB) $(LIBFT) $(FT_PRINTF_LIB)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF_LIB) $(LIBS) -o $(NAME)
	@echo "✓ $(NAME) compiled successfully"

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@rm -rf $(OBJ_DIR)
	@echo "✓ Object files cleaned"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(NAME) 
	@echo "✓ $(NAME) removed"
	
re: fclean all

test: all
	@bash tests/run_tests.sh

norm:
	norminette *.c cub3d.h libft

.PHONY: all libft clean fclean re norm test