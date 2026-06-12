#include "cub3d.h"

int	key_press(int keycode, void *ply)
{
    t_player *player;

    player = (t_player *)ply;
	if (keycode == W)
		player->forward = true;
	if (keycode == S)
		player->backward = true;
	if (keycode == D)
		player->right = true;
	if (keycode == A)
		player->left = true;
	if (keycode == LEFT)
		player->left_rotate = true;
	if (keycode == RIGHT)
		player->right_rotate = true;
	if (keycode == ESC)
		player->exit = true;
    return (0);
}

int	key_release(int keycode, void *ply)
{
    t_player *player;

    player = (t_player *)ply;
	if (keycode == W)
		player->forward = false;
	if (keycode == S)
		player->backward = false;
	if (keycode == D)
		player->right = false;
	if (keycode == A)
		player->left = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	if (keycode == ESC)
		player->exit = false;
    return (0);
}
