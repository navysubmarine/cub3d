/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <bdemouge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:08:02 by bdemouge          #+#    #+#             */
/*   Updated: 2026/06/11 14:51:02 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft.h"

# define FD_MAX 1024

char	*get_next_line(int fd);
// size_t	ft_strlen(const char *str);
// size_t	ft_strlcat(char *dst, const char *src, size_t siz);
// char	*ft_strdup(const char *s);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
