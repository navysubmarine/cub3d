/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:58:04 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/16 15:31:44 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;
	char	*cast_s;

	i = 0;
	last = 0;
	cast_s = (char *)s;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = &cast_s[i];
		i++;
	}
	if (s[i] == (char)c)
		last = &cast_s[i];
	return (last);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s;
	int		c;

	s = "ba";
	c = 's';

	printf("ft_strrchr : %p\n", ft_strrchr(s, c));
	printf("strrchr : %p\n", strrchr(s, c));
	return (0);
}
*/
