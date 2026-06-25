/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:54:54 by bdemouge          #+#    #+#             */
/*   Updated: 2026/06/25 17:55:29 by bdemouge         ###   ########.fr       */
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
	float	new_x;
	float	new_y;

	new_x = player->x;
	new_y = player->y;
	if (player->forward == true)
	{
		new_x += cos_angle * SPEED;
		new_y += sin_angle * SPEED;
	}
	if (player->backward == true)
	{
		new_x -= cos_angle * SPEED;
		new_y -= sin_angle * SPEED;
	}
	if (!touch(new_x, player->y, g))
		player->x = new_x;
	if (!touch(player->x, new_y, g))
		player->y = new_y;
}

static void	move_right_left(float cos_angle, float sin_angle, t_player *player,
		t_game *g)
{
	float	new_x;
	float	new_y;

	new_x = player->x;
	new_y = player->y;
	if (player->left == true)
	{
		new_x += sin_angle * SPEED;
		new_y -= cos_angle * SPEED;
	}
	if (player->right == true)
	{
		new_x -= sin_angle * SPEED;
		new_y += cos_angle * SPEED;
	}
	if (!touch(new_x, player->y, g))
		player->x = new_x;
	if (!touch(player->x, new_y, g))
		player->y = new_y;
}

void	move_player_collision(t_game *g)
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
