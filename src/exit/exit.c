/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:10:36 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/10 15:45:17 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*TODO:refactor global exit*/
/*
int	exit_game(t_game *g, int error)
{
	(void)g;
	//free_all(g);
	if (error)
	{
		exit(EXIT_FAILURE);
		return (1);
	}
	write(2, "\n(◡◕⏖◕)ᑐ🝐 ⠁⭒*.✩.*⭒⠁\n", 44);
	exit(EXIT_SUCCESS);
	return (0);
}
*/

int	exit_game(t_game *g, int error)
{
	(void)g;
	get_next_line(-1);
	//free_all(g);
	if (error)
	{
		exit(EXIT_FAILURE);
		return (1);
	}
	write(2, "\n(◡◕⏖◕)ᑐ🝐 ⠁⭒*.✩.*⭒⠁\n", 44);
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_content(char **content)
{
	int	i;

	if (!content)
		return ;
	i = 0;
	while (content[i])
	{
		free(content[i]);
		i++;
	}
	free(content);
}

char	*clear_stash(char *stash_array[FD_OPEN_MAX])
{
	int	i;

	i = 0;
	while (i < FD_OPEN_MAX)
	{
		if (stash_array[i])
		{
			free(stash_array[i]);
			stash_array[i] = NULL;
		}
		i++;
	}
	return (NULL);
}

/*
static void	free_images(t_game *g)
{
	if (!g || !g->mlx)
		return ;
	if (g->img.wallside)
		mlx_destroy_image(g->mlx, g->img.wallside);
	if (g->img.wallupdown)
		mlx_destroy_image(g->mlx, g->img.wallupdown);
	if (g->img.leftbotcorner)
		mlx_destroy_image(g->mlx, g->img.leftbotcorner);
	if (g->img.rightbotcorner)
		mlx_destroy_image(g->mlx, g->img.rightbotcorner);
	if (g->img.lefttopcorner)
		mlx_destroy_image(g->mlx, g->img.lefttopcorner);
	if (g->img.righttopcorner)
		mlx_destroy_image(g->mlx, g->img.righttopcorner);
	if (g->img.floor)
		mlx_destroy_image(g->mlx, g->img.floor);
	if (g->img.player_moon)
		mlx_destroy_image(g->mlx, g->img.player_moon);
	if (g->img.player)
		mlx_destroy_image(g->mlx, g->img.player);
	if (g->img.collect)
		mlx_destroy_image(g->mlx, g->img.collect);
	if (g->img.exit)
		mlx_destroy_image(g->mlx, g->img.exit);
}
*/
/*
void	free_all(t_game *g)
{
	if (!g)
		return ;
	free_content(g->file.content);
	//free_map(g->test_map);
	//free_images(g);
	if (g->win && g->mlx)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
		mlx_destroy_display(g->mlx);
	if (g->mlx)
		free(g->mlx);
		i++;
	}
	return (NULL);
}
*/