/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:02:04 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/15 09:48:49 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;
	size_t			i;

	ptrdst = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	if (ptrdst == ptrsrc)
		return (dest);
	if (ptrdst < ptrsrc)
	{
		i = 0;
		while (i < n)
		{
			ptrdst[i] = ptrsrc[i];
			i++;
		}
	}
	else
	{
		while (n--)
			ptrdst[n] = ptrsrc[n];
	}
	return (dest);
}
