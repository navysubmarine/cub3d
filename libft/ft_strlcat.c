/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:12:03 by marthoma          #+#    #+#             */
/*   Updated: 2025/11/10 14:33:24 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	init_dest_len;

	j = 0;
	i = ft_strlen(dst);
	init_dest_len = ft_strlen (dst);
	if (siz == 0)
		return (ft_strlen (src));
	while (src[j] && i < siz - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (!(siz <= init_dest_len))
		dst[i] = '\0';
	if (siz > init_dest_len)
		return (ft_strlen (src) + init_dest_len);
	else
		return (ft_strlen (src) + siz);
}
/*
int	main ()
{
char s1[20] = "bonjour";
char s2[10] = "buon";
char s1b[20] = "bonjour";
char s2b[10] = "buon";

printf("%zu\n", ft_strlcat(s1, s2, 15));
printf("%s\n", s1);
printf("%zu\n", strlcat(s1b, s2b, 15));
printf("%s\n", s1b);

	return (0);
}
*/
