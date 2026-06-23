/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:42:43 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/23 12:02:42 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_magnitude(float x)
{
	if (x < 0)
		return (-x);
	return (x);
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

/*avoids the /0 division and sets the cos/sin into very very tiny number*/
void	check_if_nb_is_zero(float *x)
{
	if (get_magnitude(*x) < 0.000001)
	{
		if (*x >= 0)
			*x = 0.000001;
		else
			*x = -0.000001;
	}
}