/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:05:06 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/20 18:24:45 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptrstruct;

	ptrstruct = (t_list *)malloc(sizeof(t_list));
	if (ptrstruct == NULL)
		return (NULL);
	ptrstruct->content = content;
	ptrstruct->next = NULL;
	return (ptrstruct);
}
