CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g3 -I$(MLX_DIR)
NAME    = cub3d

SOURCES = cub3d.c \
          src/utils/get_next_line.c src/utils/ft_split.c \
		  src/utils/print.c src/parse/parse.c src/parse/check_map.c src/parse/colors.c \
		  src/parse/utils_file.c src/parse/map.c src/parse/store.c src/exit/exit.c \
		  src/parse/check_header.c src/parse/texture.c src/parse/utils_map.c src/parse/init_structs.c

OBJETS  = $(SOURCES:.c=.o)

MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm -lz

LIBFT    = libft/libft.a

MAPS_GOOD = $(wildcard maps/good/*.cub)
MAPS_BAD  = $(wildcard maps/bad/*.cub)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJETS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJETS) \
	-Llibft -lft $(MLX_LIB) \
	-o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@$(MAKE) clean -C libft
	@cd $(MLX_DIR) && if [ -f Makefile.gen ]; then ./configure clean; fi
	rm -f $(OBJETS)

good: all clean

fclean: clean
	@$(MAKE) fclean -C libft
	@cd $(MLX_DIR) && if [ -f Makefile.gen ]; then ./configure clean; fi
	rm -f $(NAME)

re: fclean all

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
