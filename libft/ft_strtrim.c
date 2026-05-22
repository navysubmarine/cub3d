/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:37:53 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/21 18:18:55 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calcul_size(char const *s1, unsigned int v, unsigned int vr)
{
	size_t	size;

	if ((v == vr) && (ft_strlen(s1) == v))
		return (0);
	else
		size = ((ft_strlen(s1)) - (v + vr));
	return (size);
}

static unsigned int	trim_start(char const *s1, char const *set)
{
	int				i;
	int				j;
	unsigned int	v;

	i = 0;
	j = 0;
	v = 0;
	while (s1[i] && set[j])
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{	
				v++;
				j = 0;
				i++;
			}
			else
				j++;
		}
	}
	return (v);
}

static unsigned int	trim_end(char const *s1, char const *set)
{
	int				i;
	int				j;
	unsigned int	vr;

	i = ft_strlen(s1) - 1;
	j = 0;
	vr = 0;
	while (i != 0 && set[j])
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				vr++;
				j = 0;
				i--;
			}
			else
				j++;
		}
	}
	return (vr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*new;
	int				i;
	int				j;
	unsigned long	size_new;

	i = 0;
	j = 0;
	size_new = 1 + calcul_size(s1, trim_start(s1, set), trim_end(s1, set));
	new = ft_calloc(size_new, sizeof(char));
	if (!new)
		return (NULL);
	while (ft_strchr(set, s1[i]))
		i++;
	ft_strlcpy(new, s1 + i, size_new);
	return (new);
}
/*
int	main()
{
	char const *s1;
	char const *set;

	s1 = "  \t \t \n   \n\n\n\t";
	set = " \n\t";
	printf("%s", ft_strtrim(s1, set));
	printf("%d", chr_envers(s1, set));
	printf("%d", chr_endroit(s1, set));
	printf("%lu\n", calcul_new_size(s1, chr_endroit(s1, set), chr_envers(s1, set)));
	printf("%zu", ft_strlen(s1));
	return (0);
}
*/
