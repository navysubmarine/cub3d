/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:25:51 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/12 10:00:59 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	int		y;
	size_t	len_initial_dst;

	if (siz == 0)
		return (ft_strlen(src));
	len_initial_dst = ft_strlen(dst);
	i = len_initial_dst;
	y = 0;
	while (i < siz - 1 && src[y])
	{
		dst[i] = src[y];
		i++;
		y++;
	}
	dst[i] = '\0';
	if (len_initial_dst < siz)
		return (ft_strlen(src) + len_initial_dst);
	else
		return (ft_strlen(src) + siz);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	dest[30];
	char	*src = (char *)"AAAAAAAAA";

	memset(dest, 0, 30);
	memset(dest, 'B', 4);
	printf("%s\n", dest);
	printf("%zu\n", ft_strlcat(dest, src, 6));
	printf("%s\n", dest);
	return (0);
}
*/
