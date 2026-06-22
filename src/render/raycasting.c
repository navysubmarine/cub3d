/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:27:30 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/22 14:38:04 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*gets the distance from the player to the next hit point*/
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

/*sets up the dda context, is the ray going left/right,
	and where are we coming from,
inside the cell we are in.
Side_dist_/ is = ray distance until the next vertical/horizontal line
	-> this is what step_dda
will compare*/
void	init_dda_context(t_dda_context *d, t_player *player, float angle)
{
	float	abs_cos;
	float	abs_sin;

	d->cos_a = cos(angle);
	d->sin_a = sin(angle);
	/*avoids the /zero division, sets cos_a/sin_a to an extremely tiny number*/
	if (fabs(d->cos_a) < 1e-6)
		d->cos_a = (d->cos_a >= 0) ? 1e-6 : -1e-6;
	if (fabs(d->sin_a) < 1e-6)
		d->sin_a = (d->sin_a >= 0) ? 1e-6 : -1e-6;
	d->map_x = (int)(player->x / BLOCK_SIZE);
	d->map_y = (int)(player->y / BLOCK_SIZE);
	d->delta_dist_x = fabsf(BLOCK_SIZE / d->cos_a);
	d->delta_dist_y = fabsf(BLOCK_SIZE / d->sin_a);
	/*sets step_ = is towards right/left and side_dist,
		which is how far past the last line*/
	abs_cos = fabsf(d->cos_a);
	if (d->cos_a < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (player->x - d->map_x * BLOCK_SIZE) / abs_cos;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = ((d->map_x + 1) * BLOCK_SIZE - player->x) / abs_cos;
	}
	abs_sin = fabsf(d->sin_a);
	if (d->sin_a < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (player->y - d->map_y * BLOCK_SIZE) / abs_sin;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = ((d->map_y + 1) * BLOCK_SIZE - player->y) / abs_sin;
	}
	// if (d->cos_a < 0)
	// {
	// 	d->step_x = -1;
	// 	d->side_dist_x = (player->x - d->map_x * BLOCK_SIZE) / d->cos_a;
	// }
	// else
	// {
	// 	d->step_x = 1;
	// 	d->side_dist_x = ((d->map_x + 1) * BLOCK_SIZE - player->x) / d->cos_a;
	// }
	// if (d->sin_a < 0)
	// {
	// 	d->step_y = -1;
	// 	d->side_dist_y = (player->y - d->map_y * BLOCK_SIZE) / d->sin_a;
	// }
	// else
	// {
	// 	d->step_y = 1;
	// 	d->side_dist_y = ((d->map_y + 1) * BLOCK_SIZE - player->y) / d->sin_a;
	// }
}

/*compare side_dist_x and side_dist_y, the smaller one
is the closest line -> it will be the next thing to be hit
side = 0 -> vertical line
side = 1 -> horizontal line*/
void	step_dda(t_dda_context *d)
{
	if (d->side_dist_x < d->side_dist_y)
	{
		d->side_dist_x += d->delta_dist_x;
		d->map_x += d->step_x;
		d->side = 0;
	}
	else
	{
		d->side_dist_y += d->delta_dist_y;
		d->map_y += d->step_y;
		d->side = 1;
	}
}

int	find_wall_type(t_dda_context *d)
{
	if (d->side == 0)
	{
		if (d->step_x > 0)
			return (WE);
		return (EA);
	}
	if (d->step_y > 0)
		return (NO);
	return (SO);
}

void	get_hit_point(t_dda_context *d, t_player *player, float cos_a,
		float sin_a, float *hit_x, float *hit_y)
{
	float	dist;

	if (d->side == 0)
	{
		dist = d->side_dist_x - d->delta_dist_x;
		*hit_x = player->x + cos_a * dist;
		*hit_y = player->y + sin_a * dist;
	}
	else
	{
		dist = d->side_dist_y - d->delta_dist_y;
		*hit_x = player->x + cos_a * dist;
		*hit_y = player->y + sin_a * dist;
	}
}

float	get_wall_hit_fraction(t_dda_context *d, float hit_x, float hit_y)
{
	if (d->side == 0)
		return ((hit_y - (int)(hit_y / BLOCK_SIZE) * BLOCK_SIZE) / BLOCK_SIZE);
	else
		return ((hit_x - (int)(hit_x / BLOCK_SIZE) * BLOCK_SIZE) / BLOCK_SIZE);
}

t_tx_data	*get_tex_for_wall(t_game *g, t_textureid wall_type)
{
	if (wall_type == NO)
		return (&g->i.n_data);
	if (wall_type == SO)
		return (&g->i.s_data);
	if (wall_type == WE)
		return (&g->i.w_data);
	return (&g->i.e_data);
}

int	get_tex_pixel(t_tx_data *tex, int tex_x, int tex_y)
{
	char	*pixel;

	// printf("tex=%p addr=%p width=%d height=%d bpp=%d line=%d\n",
	// (void *)tex,
	// (void *)tex->addr,
	// tex->width,
	// tex->height,
	// tex->bpp,
	// tex->line_length);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	pixel = tex->addr + (tex_y * tex->line_length + tex_x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	draw_wall(int i, t_game *g, t_textureid wall_type, float dist,
		float wall_x)
{
	float		wall_height;
	int			start_y;
	int			end_y;
	int			screen_y;
	int			tex_x;
	int			tex_y;
	float		step;
	float		tex_pos;
	t_tx_data	*tex;

	wall_height = (BLOCK_SIZE * g->win_height) / dist;
	start_y = (g->win_height / 2) - (wall_height / 2);
	end_y = (g->win_height / 2) + (wall_height / 2);
	tex = get_tex_for_wall(g, wall_type);
	tex_x = (int)(wall_x * tex->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	/*for every 1 pixel I move down the screen,
	how many texture pixels should I move down the texture image.*/
	step = (float)tex->height / wall_height;
	tex_pos = (start_y < 0 ? -start_y : 0) * step;
	screen_y = start_y;
	if (screen_y < 0)
		screen_y = 0;
	while (screen_y < end_y && screen_y < g->win_height)
	{
		tex_y = (int)tex_pos;
		put_pixel(i, screen_y, get_tex_pixel(tex, tex_x, tex_y), g);
		tex_pos += step;
		screen_y++;
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

// int	find_which_type_of_wall_was_found(float x, float y, float prev_x,
// 		float prev_y, float cos_angle, float sin_angle)
// {
// 	int	x_before;
// 	int x_after;
// 	int y_before;
// 	int	y_after;

// 	x_before = (int)(prev_x / BLOCK_SIZE);
// 	x_after = (int)(x / BLOCK_SIZE);
// 	y_before = (int)(prev_y / BLOCK_SIZE);
// 	y_after = (int)(y / BLOCK_SIZE);
// 	if (x_before != x_after)
// 	{
// 		if (cos_angle > 0)
// 			return (EA);
// 		return (WE);
// 	}
// 	else if (y_before != y_after)
// 	{
// 		if (sin_angle > 0)
// 			return (SO);
// 		return (NO);
// 	}
// 	/*TODO: error case*/
// 	return (NO);
// }

void	ray(int i, float angle, t_player *player, t_game *g)
{
	t_dda_context	d;
	t_textureid		wall_type;

	init_dda_context(&d, player, angle);
	while (1)
	{
		step_dda(&d);
		if (d.map_y < 0 || d.map_x < 0 || !g->map[d.map_y]
			|| !g->map[d.map_y][d.map_x] || g->map[d.map_y][d.map_x] == '1')
		{
			wall_type = find_wall_type(&d);
			get_hit_point(&d, player, d.cos_a, d.sin_a, &d.hit_x, &d.hit_y);
			d.dist = get_distance(d.hit_x, d.hit_y, angle, player);
			d.wall_x = get_wall_hit_fraction(&d, d.hit_x, d.hit_y);
			draw_wall(i, g, wall_type, d.dist, d.wall_x);
			break ;
		}
	}
}

void	raycasting(t_game *g)
{
	float		start_angle;
	int			x;
	t_player	*player;

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
