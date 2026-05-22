/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:11:37 by marthoma          #+#    #+#             */
/*   Updated: 2026/01/22 14:16:09 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
*/
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = 0;
	if (!lst)
		return (0);
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*list;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*current;
	t_list	*tmp;

	list = NULL;
	// Ajouter des éléments à la liste chaînée
	node1 = (t_list *)malloc(sizeof(t_list));
	node1->content = strdup("Bonjour");
	node1->next = NULL;
	list = node1;  // Premier élément de la liste
	node2 = (t_list *)malloc(sizeof(t_list));
	node2->content = strdup("petit");
	node2->next = NULL;
	node1->next = node2;  // On lie node2 après node1
	node3 = (t_list *)malloc(sizeof(t_list));
	node3->content = strdup("crustace");
	node3->next = NULL;
	node2->next = node3;  // On lie node3 après node2
	printf("nombre d'elements dans la liste chainee : %d\n", ft_lstsize(list));
	current = list;
	while (current)
	{
		tmp = current->next;
		free(current->content);
		free(current);
		current = tmp;
	}
	return (0);
}
*/