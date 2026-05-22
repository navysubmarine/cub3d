/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:10:36 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/22 18:57:22 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*TODO:refactor global exit*/
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
