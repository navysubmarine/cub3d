/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:03:31 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/10 13:18:04 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char *)s;
	while (n > 0)
	{
		if (*ps == (unsigned char)c)
			return (ps);
		ps++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char    s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int		c;
	int		n;

	c = 'B';
	n = 10;
    printf("%s\n", (char *)ft_memchr(s, c, n));
    printf("%s\n", (char *)memchr(s, c, n));
    return (0);
}
*/
