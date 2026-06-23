#include "cub3d.h"

// void	init_player(float x, float y, float angle, t_player *player)
// {
// 	player->x = x;
// 	player->y = y;
// 	player->angle = angle;
// 	player->backward = false;
// 	player->forward = false;
// 	player->right = false;
// 	player->left = false;
// }

static void	rotate_player(t_player *player)
{
    double oldDirX;
    double oldPlaneX;

    oldDirX = player->dirX;
    oldPlaneX = player->planeX;
    if (player->right_rotate)
    {
        player->dirX = player->dirX * cos(-SPEED_ROTATE) - player->dirY * sin(-SPEED_ROTATE);
        player->dirY = oldDirX * sin(-SPEED_ROTATE) + player->dirY * cos(-SPEED_ROTATE);
        player->planeX = player->planeX * cos(-SPEED_ROTATE) - player->planeY * sin(-SPEED_ROTATE);
        player->planeY = oldPlaneX * sin(-SPEED_ROTATE) + player->planeY * cos(-SPEED_ROTATE);
    }
    if (player->left_rotate)
    {
        player->dirX = player->dirX * cos(SPEED_ROTATE) - player->dirY * sin(SPEED_ROTATE);
        player->dirY = oldDirX * sin(SPEED_ROTATE) + player->dirY * cos(SPEED_ROTATE);
        player->planeX = player->planeX * cos(SPEED_ROTATE) - player->planeY * sin(SPEED_ROTATE);
        player->planeY = oldPlaneX * sin(SPEED_ROTATE) + player->planeY * cos(SPEED_ROTATE);   
    }
}

static void	move_forward_backward(t_player *player, t_game *g)
{
	if (player->forward == true)
	{
        double newX;
        double newY;

        if (player->forward)
        {
            newX = player->x + player->dirX * SPEED;
            newY = player->y + player->dirY * SPEED;
        }
		if (player->backward)
        {
            newX = player->x - player->dirX * SPEED;
            newY = player->y - player->dirY * SPEED;
        }
        if (!touch(newX, player->y, g))
            player->x = newX;
        if (!touch(player->x, newY, g))
            player->y = newY;
	}
}

// static void move_right_left(float cos_angle, float sin_angle,
// 		t_player *player, t_game *g)
// {
// 	if (player->left == true)
// 	{
// 		if (!touch(player->x + sin_angle * SPEED, player->y, g))
// 			player->x += sin_angle * SPEED;
// 		if (!touch(player->x, player->y - cos_angle * SPEED, g))
// 			player->y -= cos_angle * SPEED;
// 	}
// 	if (player->right == true)
// 	{
// 		if (!touch(player->x - sin_angle * SPEED, player->y, g))
// 			player->x -= sin_angle * SPEED;
// 		if (!touch(player->x, player->y + cos_angle * SPEED, g))
// 			player->y += cos_angle * SPEED;
// 	}
// }

void	move_player(t_game *g)
{
	t_player	*player;

	player = &g->player;
	if (player->exit == true)
		exit_game(g, 0);
	rotate_player(player);
	move_forward_backward(player, g);
	//move_right_left(cos_angle, sin_angle, player, g);
}
