#include "cub3d.h"

float	get_distance(float r_x, float r_y, float r_angle, t_player *player)
{
	float	dx;
	float	dy;
	float	dist;

	dx = player->x - r_x;
	dy = player->y - r_y;
	dist = sqrt(dx * dx + dy * dy);
	dist = dist * cos(r_angle - player->angle);
	return (dist);
}

void	draw_wall(int i, float x, float y, float angle, t_game *g,
		t_textureid wall_type)
{
	float	wall_height;
	int		start_y;
	int		end_y;
	int		color;

	wall_height = (BLOCK_SIZE * g->win_height) / get_distance(x, y, angle,
			&g->player);
	start_y = (g->win_height / 2) - (wall_height / 2);
	end_y = (g->win_height / 2) + (wall_height / 2);
	color = BLUE;
	if (wall_type == NO)
		color = BLUE;
	else if (wall_type == SO)
		color = YELLOW;
	else if (wall_type == WE)
		color = PINK;
	else if (wall_type == EA)
		color = RED;
	while (start_y < end_y)
	{
		put_pixel(i, start_y, color, g);
		start_y++;
	}
}

// float	distance_from_nearest_grid_line(float x)
// {
// 	float	distance_from_prev;
// 	float	distance_from_next;

// 	distance_from_prev = x - (int)(x / BLOCK_SIZE) * BLOCK_SIZE;
// 	distance_from_next = BLOCK_SIZE - distance_from_prev;
// 	if (distance_from_prev < distance_from_next)
// 		return (distance_from_prev);
// 	return (distance_from_next);
// }

int	find_which_type_of_wall_was_found(float x, float y, float prev_x,
		float prev_y, float cos_angle, float sin_angle)
{
	int	x_before;
	int x_after;
	int y_before;
	int	y_after;

	x_before = (int)(prev_x / BLOCK_SIZE);
	x_after = (int)(x / BLOCK_SIZE);
	y_before = (int)(prev_y / BLOCK_SIZE);
	y_after = (int)(y / BLOCK_SIZE);
	if (x_before != x_after)
	{
		if (cos_angle > 0)
			return (EA);
		return (WE);
	}
	else if (y_before != y_after)
	{
		if (sin_angle > 0)
			return (SO);
		return (NO);
	}
	/*TODO: error case*/
	return (NO);
}

void	ray(int i, float angle, t_player *player, t_game *g)
{
	float		cos_angle;
	float		sin_angle;
	float		x;
	float		y;
	float		prev_x;
	float		prev_y;
	t_textureid	wall_type;

	// float	ray_size;
	// float	ray_u;
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	x = player->x;
	y = player->y;
	// ray_u = sqrt(cos_angle * cos_angle + sin_angle * sin_angle);
	// ray_size = 0;
	while (!touch(x, y, g))
	{
		prev_x = x;
		prev_y = y;
		x += cos_angle;
		y += sin_angle;
		// ray_size += ray_u;
		if (touch(x, y, g))
		{
			wall_type = find_which_type_of_wall_was_found(x, y, prev_x, prev_y,
					cos_angle, sin_angle);
			draw_wall(i, x, y, angle, g, wall_type);
		}
	}
}

void	raycasting(t_game *g)
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