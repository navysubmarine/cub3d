/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:46:38 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/24 18:04:19 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

/*INIT STRUCTS*/
void		init_game_struct(t_game *g);
void		init_context_struct(t_parse_context *data, t_parse *p);
void		init_parsing_struct(t_parse *p);
/****PARSING****/
int			parse_input(int argc, char **argv, t_game *g);
int			ft_strchr_cub(const char *s);
int			handle_file(t_parse *p, char *filename);
int			handle_file_content(t_parse *p);
int			handle_line(t_parse_context *c, t_parse *p);

char		*find_content(char *line, char *id);
int			assign_field_once(char **struct_path, char *line);
char		**store_content(char *file, int nb_of_lines);
int			validate_header_set(t_parse *p);
int			blank_line_detector(char *line);
/*MAP*/
int			is_valid_map_line(char *line);
int			map_detector(char *line);
void		store_map_line(t_parse *p, char *line, int i);
int			calculate_map_len(char **lines, int i, t_parse *p);
int			init_map(char **lines, t_parse *p, int i);
char		**map_padded_copy(char **map, t_parse *p);
char		**map_copy(char **map);
int			handle_player_pos(t_parse *p, char **map);
void		are_walls_enclosed(t_map *map, int x, int y, int nb_lines);
int			is_map_playable(t_parse *p);
int			are_there_still_spaces(t_map *map);
int			handle_map(int *i, int *i_map, t_parse *p, char **lines);
int			find_longest_line_len(char **map);
void		find_player(t_parse *p, char **map);
/*TEXTURE*/
int			validate_texture_line(char *line, t_parse *p);
int			tx_detector(char *line);
int			test_tx_path(char *tx_type, char *path);
/*COLORS*/
int			validate_color_line(char *line, t_parse *p);
int			test_rgb_format(char *content);
int			test_rgb_color(char *id, char *content);
int			store_rgb(int *values, char *content);
int			col_detector(char *line);
int			rgb_to_int(int r, int g, int b);
/*EXIT*/
int			end(t_game *g);
int			exit_game(t_game *g, int status);
void		free_content(char **content);
void		free_all(t_game *g);
void		safe_free(void *ptr);
void		free_parse(t_parse *p);
/*PRINT*/
void		print_parse(t_game *g);
void		print_map(char **map, char *name);
void		print_game(t_game *g);
/*UTILS*/
void		init_mlx_struct(t_game *g);
char		*ft_strdup_padded(const char *s, int padded_line_len);
void		print_map(char **map, char *name);
int			count_lines(int fd);
float		get_magnitude(float x);
/*PLAYER*/
void		move_player(t_game *g);
/*RENDER*/
int			key_press(int keycode, void *ply);
int			key_release(int keycode, void *ply);
void		raycasting(t_game *g);
int			draw_loop(void *param);
bool		touch(float x, float y, t_game *g);
void		put_pixel(int x, int y, int color, t_game *g);
void		fill_background_colors(t_game *g);
void		draw_wall_column(int i, t_game *g, t_textureid wall_type,
				t_dda_context *d);
void		init_dda_context(t_dda_context *d, t_player *player, float angle);
void		load_wall_sprites(t_game *g);
void		load_tex_data(void *img, t_tx_data *data);
float		get_wall_hit_fraction(t_dda_context *d, float hit_x, float hit_y);
void		get_hit_point(t_dda_context *d, t_player *player);
int			find_wall_type(t_dda_context *d);
float		get_magnitude(float x);
void		check_if_nb_is_zero(float *x);
t_tx_data	*get_correct_tex(t_game *g, t_textureid wall_type);
int			get_tex_pixel(t_tx_data *tex, int tex_x, int tex_y);
void		calculate_wall_size(t_game *g, t_dda_context *d, t_render_context *r);
#endif
