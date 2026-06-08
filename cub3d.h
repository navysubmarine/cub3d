/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:38 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/08 12:59:47 by marthoma         ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0

typedef struct s_tx_info
{
	char		*id;
	char		*word;
	char		**field;
}				t_tx_info;

typedef struct s_col_info
{
	char		*id;
	char		*word;
	int			*field;
	int			*is_set;
}				t_col_info;

typedef struct s_img
{
	int			i;
}				t_img;

typedef struct s_player
{
	int			initial_x;
	int			initial_y;
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
	int			floor[3];
	int			floor_set;
	int			ceiling[3];
	int			ceiling_set;
}				t_file;

typedef struct s_map
{
	char		**map;
	char		**copy;
	char		**padded_copy;
	int			map_h;
	bool		is_map_set;
	bool		valid;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_file		file;
	t_player	player;
	t_tx_info	textures[4];
	t_col_info	colors[2];
}				t_game;

/****PARSING INPUT FILE****/
int				ft_strchr_cub(const char *s);
int				handle_file(t_game *g, char *filename);
char			*find_content(char *line, char *id);
int				assign_field_once(char **struct_path, char *line);
int				count_lines(int fd);
char			**store_content(char *file, int nb_of_lines);
int				validate_header_set(t_file *file);
int				blank_line_detector(char	*line);
/*PARSING MAP*/
int				is_valid_map_line(char	*line);
int				map_line_detector(char *line);
void			store_map_line(t_game *g, char *line, int i);
int				calculate_map_len(char **lines, int i, t_game *g);
int				init_map(char **lines, t_game *g, int i);
char			**map_padded_copy(char **map, t_game *g);
char			**map_copy(char **map);
int				handle_player_pos(t_game *g, char **map);
void			are_walls_enclosed(t_map *map, int x, int y, int nb_lines);
/*PARSING HEADER*/
int				validate_header_set(t_file *file);
/*PARSING TEXTURE*/
int				validate_texture_line(char	*line, t_game *g);
int				texture_line_detector(char *line);
int				test_tx_path(char *tx_type, char *path);
void			init_tx_info_struct(t_game *g);
/*PARSING COLORS*/
int				validate_color_line(char *line, t_game *g);
int				test_rgb_format(char *content);
int				test_rgb_color(char	*id, char *content);
int				store_rgb(int *values, char *content);
int				color_line_detector(char *line);
void			init_col_info_struct(t_game *g);
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
/*PRINT*/
void			print_file(t_game *g);
/*UTILS*/
char			*ft_strdup_padded(const char *s, int padded_line_len);
void			print_map(char **map, char *name);
#endif