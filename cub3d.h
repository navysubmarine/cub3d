/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:38 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/22 18:56:31 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO: structure globale sur l'etat de jeu + autre structure pour le player*/

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef FD_OPEN_MAX
#  define FD_OPEN_MAX 1024
# endif

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	int			i;
}				t_img;

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_file
{
	char		**content;
}				t_file;

typedef struct s_map
{
	char		**map;
	int			map_w;
	int			map_h;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_file		file;
	t_player	player;
}				t_game;

/*CHECK MAP*/
int				ft_strchr_cub(const char *s);
/*GET NEXT LINE*/
char			*get_next_line(int fd);
char			*call_and_check(int fd, char *buffer, char **stash);
int				read_and_fill_stash(int fd, char *buffer, char **stash);
char			*update_stash(char **stash);
char			*set_line(char *stash);
char			*clear_stash(char *stash_array[FD_OPEN_MAX]);

#endif