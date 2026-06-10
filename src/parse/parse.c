/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:50:58 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/10 18:57:27 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	handle_line(t_parse_context *p, t_game *g)
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

static void	init_context_struct(t_parse_context *data, t_game *g)
{
	data->i = 0;
	data->i_map = 0;
	data->ret_map = 0;
	data->nb_l = g->file.nb_of_lines;
}

int	handle_file_content(t_game *g)
{
	t_parse_context	s;

	init_context_struct(&s, g);
	while (s.i < s.nb_l)
	{
		if (handle_line(&s, g) == 1)
			return (1);
		if (s.ret_map == 2)
			break ;
	}
	return (0);
}

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
