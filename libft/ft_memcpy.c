/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:42:13 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/18 13:53:13 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		(((char *)dest)[i]) = (((const char *)src)[i]);
		i++;
	}
	while (i < n)
	{
		(((char *)dest)[i]) = '\0';
		i++;
	}
	return (dest);
}
/*
int	main()
{
	char s1[] = "\0";
    char s2[] = "\0";
    printf("%p\n", (char *)((memcpy(s1, s2, 0))));
	printf("%p\n", (char *)((ft_memcpy(s1, s2, 0))));
    return(0);
}
*/
