#include "cub3d.h"

float get_distance(float r_x, float r_y, float r_angle, t_player *player)
{
	float dx;
	float dy;
	float dist;
	//(void)r_angle;

	dx = player->x - r_x;
	dy = player->y - r_y;
	dist = sqrt(dx * dx + dy * dy);
	dist = dist * cos(r_angle - player->angle);
	return (dist);
}



void draw_wall(int i, float x, float y, float angle, t_data *data)
{
	float wall_height;
	int start_y;
	int end_y;
	
	wall_height = (BLOCK_SIZE * data->height) / get_distance(x, y, angle, &data->player);
	start_y = (data->height / 2) - (wall_height / 2);
	end_y = (data->height / 2) + (wall_height / 2);
	while(start_y < end_y)
	{
		put_pixel(i, start_y, 0xFF, data);
		start_y++;
	}
 }

void	ray(int i, float angle, t_player *player, t_data *data)
{
	float	cos_angle;
	float	sin_angle;
	float	x;
	float	y;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	x = player->x;
	y = player->y;
	while (x < data->width && y < data->height && x >= 0 && y >= 0 && !touch(x,
			y, data))
	{
		x += cos_angle;
		y += sin_angle;
		if (touch(x, y,data))
		{
			draw_wall(i, x, y, angle, data);
		}
	}
}

#include <stdio.h>

void raycasting(t_data *data)
{
	float start_angle;
	int x;
	t_player *player;

	player = &data->player;
	start_angle = player->angle - FOV / 2;
	x = 0;
	while (start_angle < player->angle + FOV / 2)
	{
		ray(x, start_angle, player, data);
		start_angle += FOV / data->width;
		x++;
	}
}