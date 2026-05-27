/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:38 by marthoma          #+#    #+#             */
/*   Updated: 2026/05/27 16:01:52 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef FD_OPEN_MAX
#  define FD_OPEN_MAX 1024
# endif

# include "../libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 0
# define FALSE 1

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
	int			nb_of_lines;
	char		**content;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	int			ceiling[3];
	bool		ceiling_set;
	int			floor[3];
	bool		floor_set;
	char		**map;
}				t_file;

typedef struct s_map
{
	char		**map;
	int			map_w;
	int			map_h;
	bool		is_map_set;
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

/****PARSING INPUT FILE****/
int				ft_strchr_cub(const char *s);
int				handle_file(t_game *g, char *filename);
char			*find_content(char *line, char *id);
int				assign_field_once(char **struct_path, char *line);
int				count_lines(int fd);
char			**store_content(char *file, int nb_of_lines);
/*PARSING MAP*/
int				is_valid_map_line(char	*line);
int				map_line_detector(char *line);
/*PARSING TEXTURE*/
int				test_tx_path(char *tx_type, char *path);
/*GET NEXT LINE*/
char			*get_next_line(int fd);
char			*call_and_check(int fd, char *buffer, char **stash);
int				read_and_fill_stash(int fd, char *buffer, char **stash);
char			*update_stash(char **stash);
char			*set_line(char *stash);
char			*clear_stash(char *stash_array[FD_OPEN_MAX]);
/*EXIT*/
int				exit_game(t_game *g, int error);
void			free_content(char **content);
void			free_all(t_game *g);
char			*clear_stash(char *stash_array[FD_OPEN_MAX]);
/*PRINT*/
void			print_file(t_file *file);
#endif