/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:27:04 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/19 18:00:52 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	size_newstr(char const *s1, char const *set)
{
	int	i;
	int	nb_del;
	int	size;

	i = 0;
	nb_del = 0;
	size = ft_strlen(s1);
	while (s1[i] && is_in_set(s1[i], set))
	{
		nb_del++;
		i++;
	}
	if (s1[i] == '\0')
		return (size - nb_del);
	i = size - 1;
	while (i > 0 && is_in_set(s1[i], set))
	{
		nb_del++;
		i--;
	}
	return (size - nb_del);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	int		i;
	int		y;
	char	*str;

	size = size_newstr(s1, set);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	while (y < size)
	{
		str[y] = s1[i];
		y++;
		i++;
	}
	str[y] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*s1 = "\t\nabc\n";
	char	*set = "\t\n";

	str = ft_strtrim(s1, set);
	if (str[0] == 0)
		printf("\\0\n");
	printf("%s", str);
	free(str);
	return (0);
}
*/
