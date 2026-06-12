#include "cub3d.h"

bool	touch(float x, float y, t_game *g)
{
	int	real_x;
	int	real_y;

	real_x = x / BLOCK_SIZE;
	real_y = y / BLOCK_SIZE;
	if (g->map.map[real_y][real_x] == '1')
		return (true);
	return (false);
}

void	put_pixel(int x, int y, int color, t_game *g)
{
	char	*dst;

	if (x >= g->win_width || y >= g->win_height || x < 0 || y < 0)
		return ;
	dst = g->addr + (y * g->line_length + x * (g->bpp / 8));
	*(unsigned int *)dst = color;
}

int	draw_loop(void *param)
{
	t_game *g;

	g = (t_game *)param;
	ft_memset(g->addr, 0, g->win_width * g->win_height * g->bpp / 8);
	move_player(g);
	raycasting(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	return (0);
}