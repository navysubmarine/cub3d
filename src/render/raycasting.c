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
	int color;
	
	wall_height = (BLOCK_SIZE * g->win_height) / get_distance(x, y, angle, &g->player);
	start_y = (g->win_height / 2) - (wall_height / 2);
	end_y = (g->win_height / 2) + (wall_height / 2);
	color = 0;
	if ((int)x % BLOCK_SIZE == 0)
		color = 0x0000FF;
	// else if ((int)y % BLOCK_SIZE == 0 && (int)x % BLOCK_SIZE)
	// 	color = 0x00FF00;
	// else if ((int)x % BLOCK_SIZE != 0 && (int)y % BLOCK_SIZE != 0)
	// 	color = 0xFF0000;
	// else if ((int)y % BLOCK_SIZE && (int)x % BLOCK_SIZE == 0)
		// color = 0xFFFFFF;
	while(start_y < end_y)
	{
		put_pixel(i, start_y, color, g);
		start_y++;
	}
 }

void	ray(int i, float angle, t_player *player, t_game *g)
{
	float	cos_angle;
	float	sin_angle;
	float	x;
	float	y;
	float   ray_size;
	float	ray_u;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	x = player->x;
	y = player->y;
	ray_u = sqrt(cos_angle * cos_angle + sin_angle * sin_angle);
	ray_size = 0;
	while (!touch(x, y, g))
	{
		x += cos_angle;
		y += sin_angle;
		ray_size += ray_u;
		if (touch(x, y, g))
			draw_wall(i, x, y, angle, g);
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