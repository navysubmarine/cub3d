/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:42:43 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/23 12:14:03 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	get_hit_point(t_dda_context *d, t_player *player)
{
	float	dist;

	if (d->side == 0)
	{
		dist = d->side_dist_x - d->delta_dist_x;
		d->hit_x = player->x + d->cos_a * dist;
		d->hit_y = player->y + d->sin_a * dist;
	}
	else
	{
		dist = d->side_dist_y - d->delta_dist_y;
		d->hit_x = player->x + d->cos_a * dist;
		d->hit_y = player->y + d->sin_a * dist;
	}
}

float	get_wall_hit_fraction(t_dda_context *d, float hit_x, float hit_y)
{
	if (d->side == 0)
		return ((hit_y - (int)(hit_y / BLOCK_SIZE) * BLOCK_SIZE) / BLOCK_SIZE);
	else
		return ((hit_x - (int)(hit_x / BLOCK_SIZE) * BLOCK_SIZE) / BLOCK_SIZE);
}
