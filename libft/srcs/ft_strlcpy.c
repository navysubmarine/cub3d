/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:46:37 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/10 13:45:06 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	i = 0;
	if (siz > 0)
	{
		while (i < siz - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	dst1[20];
	char	dst2[20];
	char	*dst = "jhdfkalhfshfljkh";
	char 	*src = "test";
	int		siz;

	siz = -5;
	while (siz <= 30)
	{
		strcpy(dst1, dst);
		strcpy(dst2, dst);
		ft_strlcpy(dst1, src, siz);
		strlcpy(dst2, src, siz);
		printf("siz = %d\n", siz);
		printf("dest1 = %s\n", dst1);
		printf("dest2 = %s\n", dst2);
		printf("=====================\n");
		siz++;
	}
	return (0);
}
*/
