#include "cub3d.h"



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
		r->mapX = (int)p->x;
		r->mapY = (int)p->y;
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
			// if (g->map[r->mapX][r->mapY] == '1')
			// 	r->hit = 1;
		}
		if (r->side == 0)
			r->perpWallDist = r->sideDistX - r->deltaDistX;
		else
			r->perpWallDist = r->sideDistY - r->deltaDistY;
	}
}