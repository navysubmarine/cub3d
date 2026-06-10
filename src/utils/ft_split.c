/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:54:48 by marthoma          #+#    #+#             */
/*   Updated: 2026/06/10 15:45:52 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

unsigned int	calcul_nb_strings(char const *s, char c)
{
	unsigned int	i;
	unsigned int	v;
	unsigned long	len_s;

	i = 0;
	v = 0;
	if (!s[i])
		return (0);
	len_s = ft_strlen(s);
	while (s[i] == c)
		i++;
	if (s[i])
	{
		v++;
		i++;
	}
	while (i < len_s)
	{
		if ((s[i] != c && s[i - 1] == c))
			v++;
		i++;
	}
	return (v);
}

static void	*libere_toi_petit_malloc(char **tab_str, int i_tab)
{
	int	i;

	i = 0;
	while (i < i_tab)
	{
		free(tab_str[i]);
		i++;
	}
	free(tab_str);
	return (NULL);
}

static int	locate_next_start(char const *s, char c, int i_og)
{
	while (s[i_og] == c && s[i_og])
	{
		i_og++;
	}
	return (i_og);
}

static char	**fill_str(char const *s, char c,
	char **tab_str, int i_og)
{
	int		i_new_start;
	int		i_tab;
	char	*new_str;	

	i_tab = 0;
	while (s[i_og])
	{
		i_new_start = locate_next_start(s, c, i_og);
		i_og = i_new_start;
		while (s[i_og] != c && s[i_og])
		{
			i_og++;
			if (s[i_og] == c || !s[i_og])
			{
				new_str = ft_substr(s, i_new_start, (i_og - i_new_start));
				if (new_str == NULL)
					return (libere_toi_petit_malloc(tab_str, i_tab));
				tab_str[i_tab++] = new_str;
			}
		}
	}
	return (tab_str);
}

char	**ft_split(char const *s, char c)
{
	char			**tab_str;
	unsigned int	nb_strings;
	int				i_og;

	if (!s)
		return (NULL);
	i_og = 0;
	tab_str = NULL;
	nb_strings = calcul_nb_strings(s, c);
	tab_str = malloc(sizeof(char *) * (nb_strings + 1));
	if (!tab_str)
		return (NULL);
	tab_str[nb_strings] = NULL;
	return (fill_str(s, c, tab_str, i_og));
}
