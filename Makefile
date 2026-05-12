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
	utils/parsing.c \
	utils/bonus_utils.c \
	utils/bonus_utils2.c

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
	bonus/door_state_bonus.c \
	bonus/door_interact_bonus.c \
	bonus/door_tiles_bonus.c \
	bonus/door_texture_parse_bonus.c \
	bonus/door_texture_render_bonus.c

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

LIBFT      = $(LIBFT_DIR)/libft.a
MLX_LIB    = $(MLX_DIR)/libmlx.a

LIBS = \
	-L$(LIBFT_DIR) -lft \
	-L$(MLX_DIR) -lmlx \
	-lXext -lX11 -lm

CFLAGS_BONUS = $(CFLAGS) -DBONUS

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB) Makefile
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "✓ $(NAME) compiled successfully"

$(NAME_BONUS): $(OBJS_BONUS_MAIN) $(OBJS_BONUS) $(LIBFT) $(MLX_LIB) Makefile
	@echo "Linking $(NAME_BONUS)..."
	@$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS_MAIN) $(OBJS_BONUS) $(LIBS) -o $(NAME_BONUS)
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
	@rm -rf $(OBJ_DIR_BONUS)
	@echo "✓ Object files cleaned"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
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
-include $(DEPS_BONUS)

.PHONY: all bonus clean fclean re test norm
