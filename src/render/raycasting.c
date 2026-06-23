/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:27:30 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/23 12:02:05 by marthoma         ###   ########.fr       */
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

void	set_step_direction(float cos_sin, int *step)
{
	if (cos_sin < 0)
		*step = -1;
	else
		*step = 1;
}

/*sets step_ = is towards right/left and side_dist,
which is how far past the last line*/
void	get_distance_from_next_grid_line(t_dda_context *d, t_player *player)
{
	float	absolute_cos;
	float	absolute_sin;

	absolute_cos = get_magnitude(d->cos_a);
	if (d->cos_a < 0)
		d->side_dist_x = (player->x - d->map_x * BLOCK_SIZE) / absolute_cos;
	else
		d->side_dist_x = ((d->map_x + 1) * BLOCK_SIZE - player->x)
			/ absolute_cos;
	absolute_sin = get_magnitude(d->sin_a);
	if (d->sin_a < 0)
		d->side_dist_y = (player->y - d->map_y * BLOCK_SIZE) / absolute_sin;
	else
		d->side_dist_y = ((d->map_y + 1) * BLOCK_SIZE - player->y)
			/ absolute_sin;
}

/*sets up the dda context, is the ray going left/right,
	and where are we coming from,
inside the cell we are in.
Side_dist_/ is = ray distance until the next vertical/horizontal line
	-> this is what step_dda
will compare*/
void	init_dda_context(t_dda_context *d, t_player *player, float angle)
{
	d->cos_a = cos(angle);
	d->sin_a = sin(angle);
	check_if_nb_is_zero(&d->cos_a);
	check_if_nb_is_zero(&d->sin_a);
	set_step_direction(d->cos_a, &d->step_x);
	set_step_direction(d->sin_a, &d->step_y);
	d->map_x = (int)(player->x / BLOCK_SIZE);
	d->map_y = (int)(player->y / BLOCK_SIZE);
	d->delta_dist_x = get_magnitude(BLOCK_SIZE / d->cos_a);
	d->delta_dist_y = get_magnitude(BLOCK_SIZE / d->sin_a);
	get_distance_from_next_grid_line(d, player);
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
	int			bottom_y;
	int			top_y;
	int			tex_x;
	int			tex_y;
	float		step;
	float		tex_pos;
	t_tx_data	*tex;

	int screen_y; // that pixel on the screen
	wall_height = (BLOCK_SIZE * g->win_height) / dist;
	/*to find the center,
		then remove half the height to find the bottom of the wall */
	bottom_y = (g->win_height / 2) - (wall_height / 2);
	/*same but the other way around to find the top*/
	top_y = (g->win_height / 2) + (wall_height / 2);
	tex = get_tex_for_wall(g, wall_type);
	/*wall_x is the percentage of where the ray touched the wall,
	we want to find the according
	column of the texture*/
	tex_x = (int)(wall_x * tex->width);
	/*we check we won't try to read out of the texture bounds*/
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	/*for every 1 pixel I move down the screen,
	how many texture pixels should I move down the texture image ?*/
	step = tex->height / wall_height;
	/*if the wall is bigger than the screen,
		it starts at 0 = bottom of the screen
	+ we have to "skip" a part of the texture*/
	if (bottom_y < 0)
		tex_pos = -bottom_y * step;
	else
		tex_pos = 0;
	screen_y = bottom_y;
	if (screen_y < 0)
		screen_y = 0;
	/* we keep going until end of the screen or the wall*/
	while (screen_y < top_y && screen_y < g->win_height)
	{
		tex_y = (int)tex_pos;
		put_pixel(i, screen_y, get_tex_pixel(tex, tex_x, tex_y), g);
		tex_pos += step;
		screen_y++;
	}
}

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
