/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:45:09 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/10 14:07:58 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	unsigned long	i;
	unsigned long	init_src;

	init_src = ft_strlen(src);
	i = 0;
	if (siz == 0)
	{
		return (init_src);
	}
	while (i < siz - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (init_src);
}
/*
int	main()
{
	char src1a[] = "hello";
    char dest1a[] = "coucou toi";
	char src2a[] = "hello";
    char dest2a[] = "coucou toi";

    printf("%zu\n", ft_strlcpy(dest1a, src1a, 12));
	printf("%zu\n", strlcpy(dest2a, src2a, 12)); 
    return (0);
}
*/
