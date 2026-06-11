/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:48:06 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/10 10:06:12 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "ASjhdgdfshaghgjhgfadshfbksahbkhsbfkhgafkhgsdj";
	int		n;
	int		i;

	n = strlen(s);
	i = 0;
	ft_bzero(s, 0);
	while (i < n)
	{
		if (s[i] == 0)
			printf("\\0");
		else
			printf("%c", s[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
