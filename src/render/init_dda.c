/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:10:44 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/26 18:12:11 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*avoids the /0 division and sets the cos/sin into very very tiny number*/
void	check_if_nb_is_zero(float *x)
{
	if (fabs(*x) < 0.000001)
	{
		if (*x >= 0)
			*x = 0.000001;
		else
			*x = -0.000001;
	}
}

void	get_step_direction(float cos_sin, int *step)
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

	absolute_cos = fabs(d->cos_a);
	if (d->cos_a < 0)
		d->side_dist_x = (player->x - d->map_x * BLOCK_SIZE) / absolute_cos;
	else
		d->side_dist_x = ((d->map_x + 1) * BLOCK_SIZE - player->x)
			/ absolute_cos;
	absolute_sin = fabs(d->sin_a);
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
	get_step_direction(d->cos_a, &d->step_x);
	get_step_direction(d->sin_a, &d->step_y);
	d->map_x = (int)(player->x / BLOCK_SIZE);
	d->map_y = (int)(player->y / BLOCK_SIZE);
	d->delta_dist_x = fabs(BLOCK_SIZE / d->cos_a);
	d->delta_dist_y = fabs(BLOCK_SIZE / d->sin_a);
	get_distance_from_next_grid_line(d, player);
}
