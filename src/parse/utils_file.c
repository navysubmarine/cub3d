/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:19:04 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/12 15:20:06 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_file(t_parse *p, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	p->nb_of_lines = count_lines(fd);
	close (fd);
	p->content = store_content(filename, p->nb_of_lines);
	if (!p->content)
		return (1);
	return (0);
}

int	ft_strchr_cub(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if (i < 4)
		return (0);
	if (s[i - 4] == '.' && s[i - 3] == 'c' && s[i - 2] == 'u' && s[i
			- 1] == 'b')
		return (1);
	return (0);
}

char	*find_content(char *line, char *id)
{
	int	len;
	int	i;

	len = ft_strlen(id);
	if (ft_strncmp(line, id, len) != 0)
		return (NULL);
	if (line[len] != ' ' && line[len] != '\t')
		return (NULL);
	i = len;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (&line[i]);
}

int	assign_field_once(char **struct_path, char *line)
{
	if (*struct_path)
	{
		ft_putstr_fd("Error. Duplicate identifyer\n", 2);
		return (1);
	}
	*struct_path = ft_strdup(line);
	if (*struct_path == NULL)
		return (1);
	return (0);
}

int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			break ;
		}
		count++;
		safe_free(line);
	}
	return (count);
}
