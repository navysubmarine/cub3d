/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marthoma <marthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:31:17 by marthoma          #+#    #+#             */
/*   Updated: 2026/01/22 14:14:31 by marthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
int	main(void)
{
	t_list	*list;
	t_list	*node1;
	t_list	**lst;
	t_list	*node2;
	t_list	*node3;
	t_list	*new;
	t_list	*current;
	t_list	*tmp;

	list = NULL;
	// Ajouter des éléments à la liste chaînée
	node1 = (t_list *)malloc(sizeof(t_list));
	node1->content = strdup("Bonjour");
	node1->next = NULL;
	list = node1;  // Premier élément de la liste
	lst = &list;
	node2 = (t_list *)malloc(sizeof(t_list));
	node2->content = strdup("petit");
	node2->next = NULL;
	node1->next = node2;  // On lie node2 après node1
	node3 = (t_list *)malloc(sizeof(t_list));
	node3->content = strdup("crustace");
	node3->next = NULL;
	node2->next = node3;  // On lie node3 après node2
	new = (t_list *)malloc(sizeof(t_list));
	new->content = strdup("vert");
	new->next = NULL;
	ft_lstadd_back(lst, new);
	current = list;
	// Afficher la liste chaînée
	while (current)
	{
		printf("%s\n", (char *)current->content);
			// Afficher le contenu de chaque noeud
		current = current->next; // Passer au noeud suivant
	}
	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
	return (0);
}
*/