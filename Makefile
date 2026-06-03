# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        = cub3d
NAME_BONUS  = cub3d_bonus

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

MAKEFLAGS   += --no-print-directory

# **************************************************************************** #
#                                 DIRECTORIES                                  #
# **************************************************************************** #

SRC_DIR     = src
OBJ_DIR     = obj
OBJ_DIR_BONUS = obj_bonus
INC_DIR     = include

MLX_DIR     = minilibx-linux
LIBFT_DIR   = libft

# **************************************************************************** #
#                                   LIBFT                                      #
# **************************************************************************** #

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

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRC_INPUT = \
	input/read_map.c \
	input/parse_cub.c \
	input/parse_color.c \
	input/map_store.c \
	input/check_map.c \
	input/checks.c \
	input/parse_line.c \
	input/parse_texture.c


SRC_UTILS = \
	utils/free.c \
	utils/parsing.c \
	utils/bonus_utils.c

SRC_GAME = \
	game/window.c \
	game/hooks.c \
	game/player.c \
	game/player_aux.c \
	game/render.c \
	game/raycaster.c \
	game/ray_draw.c \
	game/textures.c

SRC_BONUS = \
	bonus/bonus_init_bonus.c \
	bonus/door_interact_bonus.c \
	bonus/door_tiles_bonus.c \
	bonus/door_texture_parse_bonus.c \
	bonus/door_texture_render_bonus.c \
	bonus/minimap_draw_bonus.c \
	bonus/minimap_utils_bonus.c \
	bonus/hooks_bonus.c \
	bonus/fps_bonus.c

SRC = \
	main.c \
	$(SRC_INPUT) \
	$(SRC_UTILS) \
	$(SRC_GAME)

SRCS := $(addprefix $(SRC_DIR)/,$(SRC))
SRCS_BONUS := $(addprefix $(SRC_DIR)/,$(SRC_BONUS))

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS_MAIN = $(SRCS:%.c=$(OBJ_DIR_BONUS)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJ_DIR_BONUS)/%.o)

DEPS = $(OBJS:.o=.d)
DEPS_BONUS = $(OBJS_BONUS_MAIN:.o=.d) $(OBJS_BONUS:.o=.d)
# **************************************************************************** #
#                                   HEADERS                                    #
# **************************************************************************** #

INCLUDES = -I. -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# **************************************************************************** #
#                                   LIBRARIES                                  #
# **************************************************************************** #

MLX_LIB    = $(MLX_DIR)/libmlx.a

LIBS = \
	-L$(LIBFT_DIR) -lft \
	-L$(MLX_DIR) -lmlx \
	-lXext -lX11 -lm -lz

CFLAGS_BONUS = $(CFLAGS) -DBONUS

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

bonus: $(NAME_BONUS)

$(FT_PRINTF_LIB): $(FT_PRINTF_SRCS)
	@$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory

$(LIBFT): $(LIBFT_SRCS) $(FT_PRINTF_SRCS) $(LIBFT_HEADERS)
		@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(OBJS) Makefile | $(LIBFT) $(MLX_LIB) $(FT_PRINTF_LIB)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@echo "✓ $(NAME) compiled successfully"

$(NAME_BONUS): $(OBJS_BONUS_MAIN) $(OBJS_BONUS) $(LIBFT) $(MLX_LIB) $(FT_PRINTF_LIB) Makefile
	@echo "Linking $(NAME_BONUS)..."
	@$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS_MAIN) $(OBJS_BONUS) -o $(NAME_BONUS) $(LIBS)
	@echo "✓ $(NAME_BONUS) compiled successfully"

# Compile object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling bonus $<..."
	@$(CC) $(CFLAGS_BONUS) $(INCLUDES) -MMD -MP -c $< -o $@

# MinilibX
$(MLX_LIB):
	@$(MAKE) -s -C $(MLX_DIR)

# **************************************************************************** #
#                                    CLEAN                                     #
# **************************************************************************** #

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@echo "✓ Object files cleaned"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "✓ $(NAME) removed"

re: fclean all

# **************************************************************************** #
#                                     EXTRA                                    #
# **************************************************************************** #

test: all
	@bash tests/run_tests.sh

norm:
	@norminette src include libft

# Include dependency files
-include $(DEPS)
-include $(DEPS_BONUS)

.PHONY: all bonus clean fclean re test norm
