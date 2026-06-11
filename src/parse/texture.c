/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:01:22 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/11 14:52:07 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_texture_line(char	*line, t_game *g)
{
	int		i;
	int		j;
	char	*content;

	j = 0;
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (j < 4)
	{
		if (ft_strncmp(line + i, g->textures[j].id, 2) == 0
			&& line[2 + i] != '\0')
		{
			content = find_content(line + i, g->textures[j].id);
			if (test_tx_path(g->textures[j].word, content))
				return (1);
			if (assign_field_once(g->textures[j].field, content))
				return (1);
			return (0);
		}
		j++;
	}
	return (1);
}

int	tx_detector(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(line + i, "NO ", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(line + i, "SO ", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(line + i, "WE ", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(line + i, "EA ", 3) == 0)
		return (TRUE);
	else
		return (FALSE);
}

int	test_tx_path(char *tx_type, char *path)
{
	int		fd;
	char	*trimmed;
	char	buf[1];

	trimmed = ft_strtrim(path, " \t");
	if (!trimmed)
		return (1);
	fd = open(trimmed, O_RDONLY);
	free(trimmed);
	if (fd < 0)
	{
		printf("Error. %s texture has invalid pathname\n", tx_type);
		return (1);
	}
	if (read(fd, buf, 1) < 0)
	{
		printf("Error. %s texture is a directory, not a file\n", tx_type);
		close (fd);
		return (1);
	}
	close (fd);
	return (0);
}
