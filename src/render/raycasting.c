#include "cub3d.h"

float get_distance(float r_x, float r_y, float r_angle, t_player *player)
{
	float dx;
	float dy;
	float dist;

	dx = player->x - r_x;
	dy = player->y - r_y;
	dist = sqrt(dx * dx + dy * dy);
	dist = dist * cos(r_angle - player->angle);
	return (dist);
}



void draw_wall(int i, float x, float y, float angle, t_game *g)
{
	float wall_height;
	int start_y;
	int end_y;
	
	wall_height = (BLOCK_SIZE * g->win_height) / get_distance(x, y, angle, &g->player);
	start_y = (g->win_height / 2) - (wall_height / 2);
	end_y = (g->win_height / 2) + (wall_height / 2);
	while(start_y < end_y)
	{
		put_pixel(i, start_y, 0xFF, g);
		start_y++;
	}
 }

void	ray(int i, float angle, t_player *player, t_game *g)
{
	float	cos_angle;
	float	sin_angle;
	float	x;
	float	y;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	x = player->x;
	y = player->y;
	while (x < g->win_width && y < g->win_height && x >= 0 && y >= 0 && !touch(x,
			y, g))
	{
		x += cos_angle;
		y += sin_angle;
		if (touch(x, y,g))
		{
			draw_wall(i, x, y, angle, g);
		}
	}
}

void raycasting(t_game *g)
{
	float start_angle;
	int x;
	t_player *player;

	player = &g->player;
	start_angle = player->angle - FOV / 2;
	x = 0;
	while (start_angle < player->angle + FOV / 2)
	{
		ray(x, start_angle, player, g);
		start_angle += FOV / g->win_width;
		x++;
	}
}