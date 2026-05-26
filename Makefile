CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g3 -I$(MLX_DIR)
NAME    = cub3d

SOURCES = cub3d.c \
          src/utils/get_next_line.c src/utils/ft_split.c \
		  src/parse/check_map.c \
		  src/parse/utils.c src/exit/exit.c

OBJETS  = $(SOURCES:.c=.o)

MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm -lz

LIBFT    = libft/libft.a

.PHONY: all clean fclean re

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

