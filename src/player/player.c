/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:28:12 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/24 14:28:17 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	touch(float x, float y, t_game *g)
{
	int	real_x;
	int	real_y;

	real_x = x / BLOCK_SIZE;
	real_y = y / BLOCK_SIZE;
	if (g->map[real_y][real_x] == '1')
		return (true);
	return (false);
}

static void	rotate_player(t_player *player)
{
	if (player->left_rotate)
		player->angle -= SPEED_ROTATE;
	if (player->right_rotate)
		player->angle += SPEED_ROTATE;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

static void	move_forward_backward(float cos_angle, float sin_angle,
		t_player *player, t_game *g)
{
	if (player->forward == true)
	{
		if (!touch(player->x + cos_angle * SPEED, player->y, g))
			player->x += cos_angle * SPEED;
		if (!touch(player->x, player->y + sin_angle * SPEED, g))
			player->y += sin_angle * SPEED;
	}
	if (player->backward == true)
	{
		if (!touch(player->x - cos_angle * SPEED, player->y, g))
			player->x -= cos_angle * SPEED;
		if (!touch(player->x, player->y - sin_angle * SPEED, g))
			player->y -= sin_angle * SPEED;
	}
}

static void	move_right_left(float cos_angle, float sin_angle, t_player *player,
		t_game *g)
{
	if (player->left == true)
	{
		if (!touch(player->x + sin_angle * SPEED, player->y, g))
			player->x += sin_angle * SPEED;
		if (!touch(player->x, player->y - cos_angle * SPEED, g))
			player->y -= cos_angle * SPEED;
	}
	if (player->right == true)
	{
		if (!touch(player->x - sin_angle * SPEED, player->y, g))
			player->x -= sin_angle * SPEED;
		if (!touch(player->x, player->y + cos_angle * SPEED, g))
			player->y += cos_angle * SPEED;
	}
}

void	move_player(t_game *g)
{
	float		cos_angle;
	float		sin_angle;
	t_player	*player;

	player = &g->player;
	if (player->exit == true)
		exit_game(g, 0);
	rotate_player(player);
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	move_forward_backward(cos_angle, sin_angle, player, g);
	move_right_left(cos_angle, sin_angle, player, g);
}
