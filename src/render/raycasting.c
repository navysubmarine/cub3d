/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:27:30 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/23 12:12:54 by marthoma         ###   ########.fr       */
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
			get_hit_point(&d, player);
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
