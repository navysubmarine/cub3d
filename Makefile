NAME = cub3D

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3 $(addprefix -I,$(INCDIR))
LFLAGS = -lX11 -lXext -lm
SFLAGS = -fsanitize=address

<<<<<<< HEAD
=======


>>>>>>> refs/remotes/origin/main
# Sources
CFILES	= 	$(addprefix exit/, exit.c free.c )\
			$(addprefix init/, init_p_structs.c \
			init_r_structs.c )\
			$(addprefix minimap/, minimap.c minimap_utils.c )\
			$(addprefix parse/, check_map.c colors.c \
			map_copy.c map.c parse.c store.c \
			texture.c utils_file.c utils_map.c utils_line.c )\
			$(addprefix player/, player.c )\
			$(addprefix render/, hook.c raycasting.c \
			render.c load.c dda_utils.c init_dda.c )\
			cub3d.c

SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, $(CFILES))

# Header directories
INCDIR =	inc \
			$(LIBFT_DIR)/includes \
			$(MLX_DIR)

# Build directory
BUILDDIR = .build

# Object / dependency
OBJ = $(SRC:%.c=$(BUILDDIR)/%.o)
DEP = $(OBJ:.o=.d)

# LIBRAIRIES
# Minilibx
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_DIR = minilibx
MLX_REPO = https://github.com/42paris/minilibx-linux.git

# Libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = libft

# MAPS
MAPS_GOOD = $(wildcard maps/good/*.cub)
MAPS_BAD  = $(wildcard maps/bad/*.cub)

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

fsan: CFLAGS += $(SFLAGS)
fsan: LFLAGS += $(SFLAGS)
fsan: re

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(LFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX): $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

$(MLX_DIR):
	git clone $(MLX_REPO) $(MLX_DIR)

clean:
	rm -rf $(BUILDDIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

# good: all clean

test: all
	@echo "┌──────────────────────────────────────┐"
	@echo "│  GOOD MAPS — should all succeed      │"
	@echo "└──────────────────────────────────────┘"
	@for map in $(MAPS_GOOD); do \
		echo "--- $$map ---"; \
		./$(NAME) $$map; \
		if [ $$? -eq 0 ]; then \
			echo "✅ PASS"; \
		else \
			echo "❌ FAIL (expected success)"; \
		fi \
	done
	@echo "┌──────────────────────────────────────┐"
	@echo "│  BAD MAPS — should all fail          │"
	@echo "└──────────────────────────────────────┘"
	@for map in $(MAPS_BAD); do \
		echo "--- $$map ---"; \
		./$(NAME) $$map; \
		if [ $$? -ne 0 ]; then \
			echo "✅ PASS (rejected correctly)"; \
		else \
			echo "❌ FAIL (should have been rejected)"; \
		fi \
	done

-include $(DEP)

.PHONY: clean fclean re good test

# CC      = cc
# CFLAGS  = -Wall -Wextra -Werror -g3 -I$(MLX_DIR)
# NAME    = cub3d

# SOURCES = cub3d.c \
#           src/utils/get_next_line.c src/utils/ft_split.c \
# 		  src/utils/print.c src/parse/parse.c src/parse/check_map.c src/parse/colors.c \
# 		  src/parse/utils_file.c src/parse/map.c src/parse/store.c src/exit/exit.c \
# 		  src/parse/texture.c src/parse/utils_map.c src/parse/init_structs.c \
# 		  src/parse/map_copy.c src/parse/header.c

# OBJETS  = $(SOURCES:.c=.o)

# MLX_DIR = minilibx
# MLX = $(MLX_DIR)/libmlx.a
# MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm -lz

# LIBFT    = libft/libft.a

# MAPS_GOOD = $(wildcard maps/good/*.cub)
# MAPS_BAD  = $(wildcard maps/bad/*.cub)

# .PHONY: all clean fclean re test

# all: $(NAME)

# $(NAME): $(OBJETS) $(LIBFT) $(MLX)
# 	$(CC) $(CFLAGS) $(OBJETS) \
# 	-Llibft -lft $(MLX_LIB) \
# 	-o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(MLX):
# 	@$(MAKE) -C $(MLX_DIR)

# $(LIBFT):
# 	@$(MAKE) -C libft

# clean:
# 	@$(MAKE) clean -C libft
# 	@cd $(MLX_DIR) && if [ -f Makefile.gen ]; then ./configure clean; fi
# 	rm -f $(OBJETS)

# good: all clean

# fclean: clean
# 	@$(MAKE) fclean -C libft
# 	@cd $(MLX_DIR) && if [ -f Makefile.gen ]; then ./configure clean; fi
# 	rm -f $(NAME)

# re: fclean all

# test: all
# 	@echo "┌──────────────────────────────────────┐"
# 	@echo "│  GOOD MAPS — should all succeed      │"
# 	@echo "└──────────────────────────────────────┘"
# 	@for map in $(MAPS_GOOD); do \
# 		echo "--- $$map ---"; \
# 		./$(NAME) $$map; \
# 		if [ $$? -eq 0 ]; then \
# 			echo "✅ PASS"; \
# 		else \
# 			echo "❌ FAIL (expected success)"; \
# 		fi \
# 	done
# 	@echo "┌──────────────────────────────────────┐"
# 	@echo "│  BAD MAPS — should all fail          │"
# 	@echo "└──────────────────────────────────────┘"
# 	@for map in $(MAPS_BAD); do \
# 		echo "--- $$map ---"; \
# 		./$(NAME) $$map; \
# 		if [ $$? -ne 0 ]; then \
# 			echo "✅ PASS (rejected correctly)"; \
# 		else \
# 			echo "❌ FAIL (should have been rejected)"; \
# 		fi \
# 	done
