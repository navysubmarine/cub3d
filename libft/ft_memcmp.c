/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:01:06 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/13 12:34:02 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	int				diff;

	i = 0;
	diff = 0;
	while (i < n)
	{
		if (*((unsigned char *)(s1 + i)) != *((unsigned char *)(s2 + i)))
		{
			diff = *((unsigned char *)(s1 + i)) - *((unsigned char *)(s2 + i));
			return (diff);
		}
		else
		i++;
	}
	return (diff);
}
/*
int	main(void)
{
	const char *s1;
//	const char *s2;
	const char *s3;
	const char *s4;
	const char *s5;
	const char *s6;
	const char *s7;
	const char *s8;
	char s[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};	


	s1 = "";
//	s2 = "OK";
	s3 = "Same size";
	s4 = "but different";
	s5 = "Shorter";
	s6 = "Shorter";
	s7 = "abc";
	s8 = "abcd";

//	printf("%d, %d\n", ft_memcmp(s1, s2, 0), memcmp(s1, s2, 0));
//	printf("%d, %d\n", ft_memcmp(s1, s2, 3), memcmp(s1, s2, 3));
//	printf("%d, %d\n", ft_memcmp(s3, s4, 4), memcmp(s3, s4, 4));
//  printf("%d, %d\n", ft_memcmp(s7, s8, 9), memcmp(s7, s8, 9));
	printf("%d, %d\n", ft_memcmp(s, s2, 1), memcmp(s, s2, 1));
	printf("%d, %d\n", ft_memcmp(s2, s, 1), memcmp(s2, s, 1));

}
*/
