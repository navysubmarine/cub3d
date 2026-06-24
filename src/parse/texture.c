/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:01:22 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/24 13:57:55 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_texture_line(char	*line, t_parse *p)
{
	int		i;
	int		j;
	char	*content;
	char	*trimmed;

	j = 0;
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (j < 4)
	{
		if (ft_strncmp(line + i, p->textures[j].id, 2) == 0
			&& line[2 + i] != '\0')
		{
			content = find_content(line + i, p->textures[j].id);
			trimmed = ft_strtrim(content, " \t");
			if (!trimmed)
				return (1);
			if (test_tx_path(p->textures[j].word, trimmed))
				return (safe_free(trimmed), 1);
			if (assign_field_once(&p->textures[j].path, trimmed))
				return (safe_free(trimmed), 1);
			p->textures[j].is_set = TRUE;
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
	safe_free(trimmed);
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
