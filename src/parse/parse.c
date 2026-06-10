/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:50:58 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/10 17:50:19 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	parse_input(int argc, char **argv, t_game *g)
{
	if (argc != 2 || !ft_strchr_cub(argv[1]))
	{
		ft_putstr_fd("Error. Correct input format : ./cub3d <filename>.cub\n",
			2);
		return (1);
	}
	if (handle_file(g, argv[1]))
	{
		ft_putstr_fd("Error. invalid file\n", 2);
		return (1);
	}
	if (handle_file_content(g))
		return (1);
	if (validate_header_set(&g->file))
		return (1);
	if (is_map_playable(g))
		return (1);
	return (0);
}

void	init_file_content_struct(t_parse_file_content *data, t_game *g)
{
	data->i = 0;
	data->i_map = 0;
	data->ret_map = 0;
	data->nb_l = g->file.nb_of_lines;
}

static int	handle_line(t_parse_file_content *p, t_game *g)
{
	if (blank_line_detector(g->file.content[p->i]) == TRUE)
	{
		p->i++;
		return (0);
	}
	if (!g->map.is_map_set && tx_detector(g->file.content[p->i]) == TRUE)
		return (validate_texture_line(g->file.content[p->i++], g));
	if (!g->map.is_map_set && col_detector(g->file.content[p->i]) == TRUE)
		return (validate_color_line(g->file.content[p->i++], g));
	if (map_detector(g->file.content[p->i]) == TRUE)
		return (handle_map(&p->i, &p->i_map, g, g->file.content));
	return (ft_putstr_fd("Error. Unrecognized line\n", 2), 1);
}

int	handle_file_content(t_game *g)
{
	t_parse_file_content	p;

	init_file_content_struct(&p, g);
	while (p.i < p.nb_l)
	{
		if (handle_line(&p, g) == 1)
			return (1);
		if (p.ret_map == 2)
			break ;
	}
	return (0);
}

// int	handle_file_content(t_game *g)
// {
// 	t_parse_file_content	p;
// 	int						map_set;

// 	init_file_content_struct(&p, g);
// 	map_set = g->map.is_map_set;
// 	while (p.i < p.nb_l)
// 	{
// 		if (blank_line_detector(g->file.content[p.i]) == TRUE)
// 			p.i++;
// 		else if (map_set == FALSE && tx_detector(g->file.content[p.i]) == TRUE)
// 		{
// 			if (validate_texture_line(g->file.content[p.i], g))
// 				return (1);
// 			p.i++;
// 		}
// 		else if (map_set == FALSE && col_detector(g->file.content[p.i]) == TRUE)
// 		{
// 			if (validate_color_line(g->file.content[p.i], g))
// 				return (1);
// 			p.i++;
// 		}
// 		else if (p.i < p.nb_l && map_detector(g->file.content[p.i]) == TRUE)
// 		{
// 			p.ret_map = handle_map(&p.i, &p.i_map, g, g->file.content);
// 			if (p.ret_map == 1)
// 				return (1);
// 			else if (p.ret_map == 2)
// 				break ;
// 		}
// 		else
// 			return (ft_putstr_fd("Error. Unrecognized line\n", 2), 1);
// 	}
// 	return (0);
// }

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
