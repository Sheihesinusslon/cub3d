# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        = cub3d

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

MAKEFLAGS   += --no-print-directory

# **************************************************************************** #
#                                 DIRECTORIES                                  #
# **************************************************************************** #

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = include

MLX_DIR     = minilibx-linux
LIBFT_DIR   = libft

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #
SRC_DIR = src

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
	utils/parsing.c

SRC_GAME = \
	game/window.c \
	game/hooks.c \
	game/player.c \
	game/player_aux.c \
	game/render.c \
	game/raycaster.c \
	game/ray_draw.c \
	game/textures.c

SRC = \
	main.c \
	$(SRC_INPUT) \
	$(SRC_UTILS) \
	$(SRC_GAME)

SRCS := $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

DEPS = $(OBJS:.o=.d)
# **************************************************************************** #
#                                   HEADERS                                    #
# **************************************************************************** #

INCLUDES = -I. -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# **************************************************************************** #
#                                   LIBRARIES                                  #
# **************************************************************************** #

LIBFT      = $(LIBFT_DIR)/libft.a
MLX_LIB    = $(MLX_DIR)/libmlx.a

LIBS = \
	-L$(LIBFT_DIR) -lft \
	-L$(MLX_DIR) -lmlx \
	-lXext -lX11 -lm

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB) Makefile
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "✓ $(NAME) compiled successfully"

# Compile object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# Libft
$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

# MinilibX
$(MLX_LIB):
	@$(MAKE) -s -C $(MLX_DIR)

# **************************************************************************** #
#                                    CLEAN                                     #
# **************************************************************************** #

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "✓ Object files cleaned"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "✓ $(NAME) removed"

re: fclean all

# **************************************************************************** #
#                                     EXTRA                                    #
# **************************************************************************** #

test: all
	@bash tests/run_tests.sh

norm:
	@norminette main.c src include libft

# Include dependency files
-include $(DEPS)

.PHONY: all clean fclean re test norm
