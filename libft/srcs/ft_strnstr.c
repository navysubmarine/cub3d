/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:10:21 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/06 09:54:26 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	char	*start;
	char	*cast;

	i = 0;
	cast = (char *)big;
	if (little[0] == '\0')
		return (cast);
	while (cast[i] && i < len)
	{
		if (cast[i] == little[0])
		{
			y = 0;
			start = &cast[i];
			while (cast[i + y] == little[y] && cast[i + y] && i + y < len)
			{
				y++;
				if (little[y] == '\0')
					return (start);
			}
		}
		i++;
	}
	return (0);
}
/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	*big;
	char	*little;
	char	*result;
	int		size;

	size = -5;
	while (size < 30)
	{
		big = "";
		little = "";
		printf("size = %d\n", size);
		result = ft_strnstr(big, little, size);
		printf("ft_strnstr = %s\n", result);
		result = strnstr(big, little, size);
		printf("strnstr = %s\n", result);
		printf("===============\n");
		size++;
	}
	return (0);
}
*/
