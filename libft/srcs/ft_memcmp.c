/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:18:38 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/11 15:16:54 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*ps1 == *ps2 && n > 1)
	{
		ps1++;
		ps2++;
		n--;
	}
	return (*ps1 - *ps2);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = {-128, 0, 127, 0};
	char	s2[] = {0, 0, 127, 0};
	int		n;

	n = 0;
	printf("ft_memcmp = %d\n", ft_memcmp(s1, s2, n));
	printf("memcmp = %d\n", memcmp(s1, s2, n));
	return (0);
}
*/
