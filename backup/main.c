/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:36:45 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/21 19:04:44 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	t_list	*lista = NULL;
	t_list	*nodo1;
	t_list	*nodo2;
	t_list	*modified_list;

	// Create nodes using ft_lstnew
	nodo1 = ft_lstnew(strdup("hola"));
	if (!nodo1)
		return (1);
	ft_lstadd_back(&lista, nodo1);

	nodo2 = ft_lstnew(strdup("adios"));
	if (!nodo2)
		return (1);
	ft_lstadd_back(&lista, nodo2);

	// Print original content
	printf("Original list:\n");
	printf("Nodo 1: %s\n", (char *)nodo1->content);
	printf("Nodo 2: %s\n\n", (char *)nodo2->content);

	// Create modified list using ft_lstmap
	modified_list = ft_lstmap(lista, &ft_f, &ft_del);
	if (!modified_list)
	{
		printf("Error: ft_lstmap failed\n");
		ft_lstclear(&lista, &ft_del);
		return (1);
	}

	// Print modified content
	printf("Modified list:\n");
	printf("Modified Nodo 1: %s\n", (char *)modified_list->content);
	printf("Modified Nodo 2: %s\n", (char *)modified_list->next->content);

	// Clean up memory
	ft_lstclear(&lista, &ft_del);
	ft_lstclear(&modified_list, &ft_del);

	return (0);
}
