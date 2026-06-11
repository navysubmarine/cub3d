/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:37:46 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/11 15:46:52 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;
	size_t	i;

	pdest = dest;
	psrc = (char *)src;
	i = 0;
	if (pdest < psrc)
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	if (pdest > psrc)
	{
		while (n > 0)
		{
			pdest[n - 1] = psrc[n - 1];
			n--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	ft_dest[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int		d;
	int		s;
	int		n;

	d = 0;
	s = 0;
	n = 30;
	printf("%s\n", (char *)ft_memmove(&ft_dest[d], &ft_dest[s], n));
	printf("%s\n", (char *)memmove(&dest[d], &dest[s], n));
	return (0);
}
*/
