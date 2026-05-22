/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:11:11 by marthoma          #+#    #+#             */
/*   Updated: 2026/02/03 12:08:05 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}
/*
int main()
{
	const char *s;
	int	c;

	s ="bonjour \x88 petit crustace";
	c = 'p';

	printf("%s\n", ft_strchr(s, '\x88'));
	printf("%s\n", strchr(s, '\x88'));
	printf("%s\n", strrchr(s, c + 256));
	return (0);
}
*/
