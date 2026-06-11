/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:47:42 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/17 10:20:43 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = 1;
	tmp = lst;
	if (tmp == NULL)
		return (0);
	while (tmp->next)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	n1;
	t_list	n2;
	t_list	n3;
	t_list	n4;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = NULL;
	printf("%d\n", ft_lstsize(&n4));
	return (0);
}
*/
