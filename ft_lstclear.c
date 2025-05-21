/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:03:06 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/20 19:15:16 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*actual;
	t_list	*next;

	if (!lst || !del)
		return ;
	actual = *lst;
	while (actual)
	{
		next = actual->next;
		ft_lstdelone(actual, del);
		actual = next;
	}
	*lst = NULL;
}
