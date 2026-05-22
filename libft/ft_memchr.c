/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:23:44 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/11 13:58:39 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;

	i = 0;
	while (i < n)
	{
		if (*((char *)(s + i)) == (char) c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
/*
int	main()
{
    const char *s;
    int c;
	unsigned long	n;

    s ="vlou vlou";
    c = 'b';
	n = 15;

    printf("%p\n", ft_memchr(s, c, n));
    printf("%p\n", memchr(s, c, n));
    return (0);
}
*/
