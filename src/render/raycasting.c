#include "cub3d.h"



void	raycasting(t_game *g)
{
//	float start_angle;
	int x;
	t_player *player;

	player = &g->player;
//	start_angle = player->angle - FOV / 2;
	x = 0;
	printf("%lf\n%d\n", player->dirX, x);
	// while (start_angle < player->angle + FOV / 2)
	// {
	// 	ray(x, start_angle, player, g);
	// 	start_angle += FOV / g->win_width;
	// 	x++;
	// }
}