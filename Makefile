CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g3
NAME    = cub3d

SOURCES = cub3d.c \
          src/gnl/get_next_line.c src/parse/check_map.c \
		  src/parse/utils.c src/exit/exit.c

OBJETS  = $(SOURCES:.c=.o)

# MLX_DIR = minilibx-linux
# MLX = $(MLX_DIR)/libmlx.a
# MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm -lz

LIBFT    = libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJETS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJETS) \
	-Llibft -lft \
	-o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# $(MLX):
# 	@$(MAKE) -C minilibx-linux

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@$(MAKE) clean -C libft
# 	@$(MAKE) clean -C minilibx-linux
	rm -f $(OBJETS)

good: all clean

fclean: clean
	@$(MAKE) fclean -C libft
# 	@$(MAKE) fclean -C minilibx-linux
	rm -f $(NAME)

re: fclean all

