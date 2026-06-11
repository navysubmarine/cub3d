/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:52:48 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/13 10:48:09 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int				i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s = "kfsajsafjahfjk \x88 dsjafh\n";
	int		c = 'z';
	char	*ft;
	char	*r;

	ft = ft_strchr(s, c);
	r = strchr(s, c);
	printf("%p\n", ft);
	printf("%p\n", r);
	return 0;
}
*/
