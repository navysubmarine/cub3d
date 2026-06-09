/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:50:58 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/09 15:22:21 by marthoma         ###   ########.fr       */
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

int	handle_file_content(t_game *g)
{
	int		i;
	int		i_map;
	char	**lines;
	int		ret_map;

	i = 0;
	i_map = 0;
	ret_map = 0;
	lines = g->file.content;
	while (i < g->file.nb_of_lines)
	{
		if (blank_line_detector(lines[i]) == TRUE)
			i++;
		else if (g->map.is_map_set == FALSE
			&& texture_line_detector(lines[i]) == TRUE)
		{
			if (validate_texture_line(lines[i], g))
				return (1);
			i++;
		}
		else if (g->map.is_map_set == FALSE
			&& color_line_detector(lines[i]) == TRUE)
		{
			if (validate_color_line(lines[i], g))
				return (1);
			i++;
		}
		else if (i < g->file.nb_of_lines && map_line_detector(lines[i]) == TRUE)
		{
			ret_map = handle_map(&i, &i_map, g, lines);
			if (ret_map == 1)
				return (1);
			else if (ret_map == 2)
				break ;
		}
		else
		{
			ft_putstr_fd("Error. Unrecognized line\n", 2);
			return (1);
		}
		// 	printf("DEBUG: line %d\n", i);
	}
	//print_file(g);
	//ft_putstr_fd("OK, file is valid. Ready to launch !!\n", 1);
	return (0);
}

int	blank_line_detector(char	*line)
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
