/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:29:06 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/10 19:24:30 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	content;
	unsigned char	*position;
	size_t			i;

	i = 0;
	content = (unsigned char)c;
	position = (unsigned char *)s;
	while (i < n)
	{
		position[i] = content;
		i++;
	}
	return (s);
}
