/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:34:38 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/22 20:16:30 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;
	size_t			i;

	i = 0;
	ptrs1 = (unsigned char *)s1;
	ptrs2 = (unsigned char *)s2;
	while (i < n && s1[i] && s2[i] && ptrs1[i] == ptrs2[i])
		i++;
	if (i == n)
		return (0);
	return (ptrs1[i] - ptrs2[i]);
}
/*
int	main(void)
{
	int	res;

	res = ft_strncmp("t", "", 0);
	return (res);
}*/
