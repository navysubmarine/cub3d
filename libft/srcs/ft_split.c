/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:07:39 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/19 17:40:16 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	nb_substr(const char *s, char c)
{
	int	nb;
	int	i;

	nb = 0;
	i = 1;
	if (ft_strlen(s) == 0)
	{
		return (0);
	}
	while (s[i])
	{
		if (s[i] == c)
		{
			if (s[i - 1] != c)
				nb++;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb++;
	return (nb);
}

static char	*split_dup(char const *s, char c)
{
	char	*dup;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}

static void	free_array(char **array, int y)
{
	while (y >= 0)
		free(array[y--]);
	free(array);
}

static int	init_array(char	**array, const char *s, char c)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			array[y] = split_dup(&s[i], c);
			if (array[y] == NULL)
			{
				free_array(array, y);
				return (0);
			}
			y++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	array[y] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	array = malloc(sizeof(char *) * (nb_substr(s, c) + 1));
	if (array == NULL)
		return (NULL);
	if (init_array(array, s, c))
		return (array);
	else
		return (NULL);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char	**split;
	int		i;

//	if (ac == 3)
//	{
//		split = ft_split(av[1], av[2][0]);
		split = ft_split("\0fhshfds\0 djfhl", '\0');
		i = 0;
		if (split == NULL)
		{
			printf("NULL\n");
			return (0);
		}
		while (split[i] != NULL)
		{
			if (split[i][0] == '\0')
				printf("\\0\n");
			printf("%s\n", split[i]);		
			i++;
		}
		if (split[i] == NULL)
			printf("NULL\n");
		if (split)
			free_array(split, i);
//	}
	return (0);
}
*/
