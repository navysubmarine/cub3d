/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:28:12 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/25 17:53:05 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int		new_map_x;
	int		new_map_y;

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
	new_map_x = (int)new_x / BLOCK_SIZE;
	new_map_y = (int)new_y / BLOCK_SIZE;
	if (new_map_y > 0 && g->map[new_map_y])
		player->y = new_y;
	if (new_map_x > 0 && g->map[(int)player->y / BLOCK_SIZE]
		&& g->map[(int)player->y / BLOCK_SIZE][new_map_x])
		player->x = new_x;
}

static void	move_right_left(float cos_angle, float sin_angle, t_player *player,
		t_game *g)
{
	float	new_x;
	float	new_y;
	int		new_map_x;
	int		new_map_y;

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
	new_map_x = (int)new_x / BLOCK_SIZE;
	new_map_y = (int)new_y / BLOCK_SIZE;
	if (new_map_y > 0 && g->map[new_map_y])
		player->y = new_y;
	if (new_map_x > 0 && g->map[(int)player->y / BLOCK_SIZE]
		&& g->map[(int)player->y / BLOCK_SIZE][new_map_x])
		player->x = new_x;
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
