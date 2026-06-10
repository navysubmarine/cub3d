/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:22:05 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/10 18:58:07 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_next_line(int fd)
{
	static char	*stash[FD_OPEN_MAX];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_OPEN_MAX)
		return (clear_stash(stash), NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		if (stash[fd])
			return (free(stash[fd]), stash[fd] = NULL, NULL);
		return (NULL);
	}
	buffer[0] = '\0';
	if (!stash[fd])
	{
		stash[fd] = malloc(BUFFER_SIZE + 1);
		if (!stash[fd])
			return (free(buffer), NULL);
		(stash[fd])[0] = '\0';
	}
	line = call_and_check(fd, buffer, &stash[fd]);
	return (free(buffer), line);
}

int	read_and_fill_stash(int fd, char *buffer, char **stash)
{
	ssize_t	nb_read;
	char	*temp;

	while (!ft_strchr(*stash, '\n'))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(*stash);
			*stash = NULL;
			return (0);
		}
		if (nb_read == 0)
			break ;
		buffer[nb_read] = '\0';
		temp = ft_strjoin(*stash, buffer);
		if (!temp)
			return (0);
		free(*stash);
		*stash = temp;
	}
	return (1);
}

char	*update_stash(char **stash)
{
	char	*line;
	char	*new_stash;

	line = set_line(*stash);
	if (!line)
		return (free(*stash), *stash = NULL, NULL);
	new_stash = ft_substr(*stash, ft_strlen(line),
			ft_strlen(*stash) - ft_strlen(line));
	if (!new_stash)
		return (free(line), free(*stash), *stash = NULL, NULL);
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*call_and_check(int fd, char *buffer, char **stash)
{
	if (!read_and_fill_stash(fd, buffer, stash))
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	return (update_stash(stash));
}

char	*set_line(char *stash)
{
	char	*terminating_char;
	size_t	len_final_line;
	char	*final_line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	terminating_char = ft_strchr(stash, '\n');
	if (terminating_char)
	{
		len_final_line = terminating_char - stash + 1;
		final_line = ft_substr(stash, 0, len_final_line);
	}
	else
		final_line = ft_strdup(stash);
	return (final_line);
}
