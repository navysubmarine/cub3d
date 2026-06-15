/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:10:36 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/15 15:21:55 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

// int	exit_game(t_game *g, int error)
// {
// 	(void)g;
// 	get_next_line(-1);
// 	//free_all(g);
// 	if (error)
// 	{
// 		exit(EXIT_FAILURE);
// 		return (1);
// 	}
// 	write(2, "\n(◡◕⏖◕)ᑐ🝐 ⠁⭒*.✩.*⭒⠁\n", 44);
// 	exit(EXIT_SUCCESS);
// 	return (0);
// }



int end(t_game *g)
{
	exit_game(g, 0);
	return (1);
}

// void	destroy_image()

int exit_game(t_game *g, int status)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->i.n_wall)
		mlx_destroy_image(g->mlx, g->i.n_wall);
	if (g->i.s_wall)
		mlx_destroy_image(g->mlx, g->i.s_wall);
	if (g->i.e_wall)
		mlx_destroy_image(g->mlx, g->i.e_wall);
	if (g->i.w_wall)
		mlx_destroy_image(g->mlx, g->i.w_wall);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		safe_free(g->mlx);
	}
	// free_content(g->map.map);
	// free_content(g->map.copy);
	// free_content(g->map.padded_copy);
	// free_content(g->file.content);
	// safe_free(g->file.path_no);
	// safe_free(g->file.path_so);
	// safe_free(g->file.path_we);
	// safe_free(g->file.path_ea);
	// safe_free(g->textures[0].id);
	// safe_free(g->textures[0].word);
	// free_content(g->textures[0].field);
	// safe_free(g->textures[1].id);
	// safe_free(g->textures[1].word);
	// free_content(g->textures[1].field);
	// safe_free(g->textures[2].id);
	// safe_free(g->textures[2].word);
	// free_content(g->textures[2].field);
	// safe_free(g->textures[3].id);
	// safe_free(g->textures[3].word);
	// free_content(g->textures[3].field);
	// safe_free(g->colors[0].id);
	// safe_free(g->colors[0].word);
	// safe_free(g->colors[0].field);
	// safe_free(g->colors[0].is_set);
	// safe_free(g->colors[1].id);
	// safe_free(g->colors[1].word);
	// safe_free(g->colors[1].field);
	// safe_free(g->colors[1].is_set);
	exit(status);
	return (1);	
}

// char	*clear_stash(char *stash_array[FD_OPEN_MAX])
// {
// 	int	i;

// 	i = 0;
// 	while (i < FD_OPEN_MAX)
// 	{
// 		if (stash_array[i])
// 		{
// 			free(stash_array[i]);
// 			stash_array[i] = NULL;
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

/*
static void	free_images(t_game *g)
{
	if (!g || !g->mlx)
		return ;
	if (g->img.wallside)
		mlx_destroy_image(g->mlx, g->i.wallside);
	if (g->img.wallupdown)
		mlx_destroy_image(g->mlx, g->i.wallupdown);
	if (g->img.leftbotcorner)
		mlx_destroy_image(g->mlx, g->i.leftbotcorner);
	if (g->img.rightbotcorner)
		mlx_destroy_image(g->mlx, g->i.rightbotcorner);
	if (g->img.lefttopcorner)
		mlx_destroy_image(g->mlx, g->i.lefttopcorner);
	if (g->img.righttopcorner)
		mlx_destroy_image(g->mlx, g->i.righttopcorner);
	if (g->img.floor)
		mlx_destroy_image(g->mlx, g->i.floor);
	if (g->img.player_moon)
		mlx_destroy_image(g->mlx, g->i.player_moon);
	if (g->img.player)
		mlx_destroy_image(g->mlx, g->i.player);
	if (g->img.collect)
		mlx_destroy_image(g->mlx, g->i.collect);
	if (g->img.exit)
		mlx_destroy_image(g->mlx, g->i.exit);
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