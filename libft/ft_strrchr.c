/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:11:11 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/13 11:49:56 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s[i] == '\0' && ((char)c) != '\0')
		return (0);
	if (s[i] == '\0')
		return ((char *)s);
	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + i));
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
/*
int main()
{
	const char *s;
	int	c;

	s ="";
	c = 'V';

	printf("%p\n", ft_strrchr(s, c));
	printf("%p\n", strchr(s, c));
	printf("%p\n", strrchr(s, c));
	return (0);
}
*/
