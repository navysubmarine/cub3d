/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:50:58 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/16 17:51:43 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	blank_line_detector(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		return (TRUE);
	while (line[i] == ' ' || line[i] == '\t')
	{
		i++;
	}
	if (line[i] == '\0' || line[i] == '\n')
		return (TRUE);
	else
		return (FALSE);
}

int	rgb_to_int(int r, int g, int b)
{
	int	color;

	color = r << 16;
	color += g << 8;
	color += b;
	return (color);
}

void	init_game_info(t_game *g)
{
	g->floor = rgb_to_int(g->p.colors[0].rgb[0], g->p.colors[0].rgb[1],
			g->p.colors[0].rgb[2]);
	g->ceiling = rgb_to_int(g->p.colors[1].rgb[0], g->p.colors[1].rgb[1],
			g->p.colors[1].rgb[2]);
	g->path_no_tx = g->p.textures[NO].path;
	g->path_so_tx = g->p.textures[SO].path;
	g->path_we_tx = g->p.textures[WE].path;
	g->path_ea_tx = g->p.textures[EA].path;
	g->map = g->p.map.map;
	g->player.x = g->p.player.x * BLOCK_SIZE + BLOCK_SIZE / 2;
	g->player.y = g->p.player.y * BLOCK_SIZE + BLOCK_SIZE / 2;
	g->player.angle = g->p.player.angle;
}

int	parse_input(int argc, char **argv, t_game *g)
{
	if (argc != 2 || !ft_strchr_cub(argv[1]))
	{
		ft_putstr_fd("Error. Correct input format : ./cub3d <filename>.cub\n",
			2);
		return (1);
	}
	if (handle_file(&g->p, argv[1]))
	{
		ft_putstr_fd("Error. invalid file\n", 2);
		return (1);
	}
	if (handle_file_content(&g->p))
		return (1);
	//print_parse(g);
	if (validate_header_set(&g->p))
		return (1);
	if (is_map_playable(&g->p))
		return (1);
	init_game_info(g);
	//print_game(g);
	return (0);
}

int	handle_line(t_parse_context *c, t_parse *p)
{
	if (blank_line_detector(p->content[c->i]) == TRUE)
	{
		c->i++;
		return (0);
	}
	if (!p->map.is_map_set && tx_detector(p->content[c->i]) == TRUE)
		return (validate_texture_line(p->content[c->i++], p));
	if (!p->map.is_map_set && col_detector(p->content[c->i]) == TRUE)
		return (validate_color_line(p->content[c->i++], p));
	if (map_detector(p->content[c->i]) == TRUE)
		return (handle_map(&c->i, &c->i_map, p, p->content));
	return (ft_putstr_fd("Error. Unrecognized line\n", 2), 1);
}

int	handle_file_content(t_parse *p)
{
	t_parse_context	s;

	init_context_struct(&s, p);
	while (s.i < s.nb_l)
	{
		if (handle_line(&s, p) == 1)
			return (1);
		if (s.ret_map == 2)
			break ;
	}
	return (0);
}

int	validate_header_set(t_parse *p)
{
	if (!p->textures[NO].is_set)
		return (ft_putstr_fd("Error. Missing north texture\n", 2), 1);
	if (!p->textures[SO].is_set)
		return (ft_putstr_fd("Error. Missing south texture\n", 2), 1);
	if (!p->textures[WE].is_set)
		return (ft_putstr_fd("Error. Missing west texture\n", 2), 1);
	if (!p->textures[EA].is_set)
		return (ft_putstr_fd("Error. Missing east texture\n", 2), 1);
	if (p->colors[0].is_set == FALSE)
		return (ft_putstr_fd("Error. Missing floor color\n", 2), 1);
	if (p->colors[1].is_set == FALSE)
		return (ft_putstr_fd("Error. Missing ceiling color\n", 2), 1);
	return (0);
}
