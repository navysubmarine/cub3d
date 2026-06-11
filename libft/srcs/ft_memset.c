/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:08:37 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/12 17:21:09 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    int	ft[20];
	int	r[20];
	int	i = 0;

	ft_memset(ft, 1042, sizeof(int) * 20);
	memset(r, 1042, sizeof(int) * 20);
	printf("=== ft_memset ===\n");
	while (i <  20)
	{
		printf("%d\n", ft[i]);
		i++;
	}
	i = 0;
	printf("=== memset ===\n");
	while (i < 20)
	{
		printf("%d\n", r[i]);
		i++;
	}
    return (0);
}
*/
