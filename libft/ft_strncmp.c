/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:39:04 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/13 16:42:52 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	unsigned long	diff;

	i = 0;
	diff = 0;
	while ((s1[i] || s2[i]) && n > i)
	{
		if (s1[i] != s2[i])
		{
			diff = (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
			return (diff);
		}
		i++;
	}
	return (diff);
}
/*
int	main(void)
{
	char s1[] = "";
	char s2[] = "OK";
	char s3[] = "Same";
	char s4[] = "Size";
	char s5[] = "QP";
	char s6[] = "PQ";
	
	printf("%d, %d\n", ft_strncmp(s1, s2, 2), strncmp(s1, s2, 2));
	printf("%d, %d\n", ft_strncmp(s3, s4, 5), strncmp(s3, s4, 5));
	printf("%d, %d\n", ft_strncmp(s5, s6, 0), strncmp(s5, s6, 0));
	printf("%d, %d\n", ft_strncmp(s5, s5, 2), strncmp(s5, s5, 2));

}
*/
