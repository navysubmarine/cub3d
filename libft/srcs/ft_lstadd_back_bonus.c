/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:06:37 by bdemouge          #+#    #+#             */
/*   Updated: 2025/11/17 10:18:32 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last == NULL)
		*lst = new;
	else
		last->next = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*l = NULL;
	t_list	*l2 = NULL;
	int	c1 = 1;
	int	c2 = 2;
	int c3 = 3;
	int c4 = 4;

	ft_lstadd_back(&l, ft_lstnew(&c1));
	ft_lstadd_back(&l, ft_lstnew(&c2));
	ft_lstadd_back(&l2, ft_lstnew(&c3));
	ft_lstadd_back(&l2, ft_lstnew(&c4));
	ft_lstadd_back(&l, l2);
	while (l->next)
	{
		printf("%d\n", *(int *)l->content);
		l = l->next;
	}
	return (0);
}
*/
