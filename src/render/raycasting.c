#include "cub3d.h"

void	draw_line(int x, int wall_height, int color, t_game *g)
{
	int start;
	int end;

	start = g->win_height / 2 - wall_height / 2;
	end = g->win_height / 2 + wall_height / 2;
	while (start < end)
	{
		put_pixel(x, start, color, g);
		start++;
	}
}

void	raycasting(t_game *g)
{
	int x;
	t_player *p;
	t_ray	*r;

	p = &g->player;
	r = &g->ray;
	x = -1;
	r->posX = p->x;
	r->posY = p->y;
	while (++x < g->win_width)
	{
		r->cameraX = 2 * x / (double)g->win_width - 1;
		r->rayDirX = p->dirX + p->planeX * r->cameraX;
		r->rayDirY = p->dirY + p->planeY * r->cameraX;
		r->mapX = (int)(p->x / BLOCK_SIZE);
		r->mapY = (int)(p->y / BLOCK_SIZE);
		if (r->rayDirX == 0)
			r->rayDirX = 1e-9;
		if (r->rayDirY == 0)
			r->rayDirY = 1e-9;
		r->deltaDistX = sqrt(1 + (r->rayDirY * r->rayDirY) / (r->rayDirX * r->rayDirX));
		r->deltaDistY = sqrt(1 + (r->rayDirX * r->rayDirX) / (r->rayDirY * r->rayDirY));
		if (r->rayDirX < 0)
		{
			r->stepX = -1;
			r->sideDistX = (r->posX - r->mapX) * r->deltaDistX; 
		}
		else
		{
			r->stepX = 1;
			r->sideDistX = (r->mapX + 1.0 - r->posX) * r->deltaDistX;
		}
		if (r->rayDirY < 0)
		{
			r->stepY = -1;
			r->sideDistY = (r->posY - r->mapY) * r->deltaDistY;
		}
		else
		{
			r->stepY = 1;
			r->sideDistY = (r->mapY + 1.0 - r->posY) * r->deltaDistY;
		}
		r->hit = 0;
		while (!r->hit)
		{
			if (r->sideDistX < r->sideDistY)
			{
				r->sideDistX += r->deltaDistX;
				r->mapX += r->stepX;
				r->side = 0;
			}
			else
			{
				r->sideDistY += r->deltaDistY;
				r->mapY += r->stepY;
				r->side = 1;
			}
			if (g->map[r->mapY][r->mapX] == '1')
				r->hit = 1;
		}
		if (r->side == 0)
			r->perpWallDist = r->sideDistX - r->deltaDistX;
		else
			r->perpWallDist = r->sideDistY - r->deltaDistY;
		r->wall_height = (g->win_height * BLOCK_SIZE) / r->perpWallDist;
		draw_line(x, r->wall_height, 0x0000FF, g);
	}
}