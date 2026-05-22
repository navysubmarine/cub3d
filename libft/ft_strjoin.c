/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:45:32 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/21 18:17:30 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	int		i;
	char	*total_str;
	int		len_s1;
	int		len_s2;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total_size = len_s1 + len_s2 + 1;
	total_str = malloc(sizeof(char const) * (total_size));
	if (total_str == 0)
		return (0);
	while (i < len_s1)
	{
		total_str[i] = s1[i];
		i++;
	}
	while (i < total_size - 1)
	{
		total_str[i] = s2[i - len_s1];
		i++;
	}
	total_str[i] = '\0';
	return (total_str);
}
/*
int	main()
{
	char s1[] = {'c', 'o', 'u', 'c', 'o', 'u', '\0'};
	char s2[] = {'b', 'a', 'n', 'd', 'e', '\0'};
	char *total_str;

	total_str =	ft_strjoin(s1, s2);
	printf("contenu string finale : %s\n", total_str);
	printf("pointeur string finale : %p\n", total_str);
	printf("pointeur s1 : %p\n", s1);
	printf("pointeur s2 : %p\n", s2);
	free(total_str);
}
*/
