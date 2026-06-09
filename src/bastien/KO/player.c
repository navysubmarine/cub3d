#include "cub3d.h"

void	init_player(float x, float y, float angle, t_player *player)
{
	player->x = x;
	player->y = y;
	player->angle = angle;
	player->backward = false;
	player->forward = false;
	player->right = false;
	player->left = false;
}

static void	rotate_player(t_player *player)
{
	if (player->left_rotate)
		player->angle -= SPEED_ROTATE;
	if (player->right_rotate)
		player->angle += SPEED_ROTATE;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if(player->angle < 0)
		player->angle = 2  * PI;
}

static void	move_forward_backward(float cos_angle, float sin_angle,
		t_player *player, t_data *data)
{
	if (player->forward == true)
	{
		if (!touch(player->x + cos_angle * SPEED, player->y, data))
			player->x += cos_angle * SPEED;
		if (!touch(player->x, player->y + sin_angle * SPEED, data))
			player->y += sin_angle * SPEED;
	}
	if (player->backward == true)
	{
		if (!touch(player->x - cos_angle * SPEED, player->y, data))
			player->x -= cos_angle * SPEED;
		if (!touch(player->x, player->y - sin_angle * SPEED, data))
			player->y -= sin_angle * SPEED;
	}
}

static void move_right_left(float cos_angle, float sin_angle,
		t_player *player, t_data *data)
{
	if (player->left == true)
	{
		if (!touch(player->x + sin_angle * SPEED, player->y, data))
			player->x += sin_angle * SPEED;
		if (!touch(player->x, player->y - cos_angle * SPEED, data))
			player->y -= cos_angle * SPEED;
	}
	if (player->right == true)
	{
		if (!touch(player->x - sin_angle * SPEED, player->y, data))
			player->x -= sin_angle * SPEED;
		if (!touch(player->x, player->y + cos_angle * SPEED, data))
			player->y += cos_angle * SPEED;
	}
}

void	move_player(t_data *data)
{
	float		cos_angle;
	float		sin_angle;
	t_player	*player;

	player = &data->player;
	rotate_player(player);
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	move_forward_backward(cos_angle, sin_angle, player, data);
	move_right_left(cos_angle, sin_angle, player, data);
}
