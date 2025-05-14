/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:31:02 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/11 16:51:43 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;
	size_t			i;

	i = 0;
	ptrs1 = (unsigned char *)s1;
	ptrs2 = (unsigned char *)s2;
	while (i < n && ptrs1[i] == ptrs2[i])
		i++;
	if (i == n)
		return (0);
	return (ptrs1[i] - ptrs2[i]);
}
