/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:11:05 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/15 19:34:36 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n && p[i] != (unsigned char)c)
		i++;
	if (p[i] == (unsigned char)c)
		return ((void *)(p + i));
	return (NULL);
}
