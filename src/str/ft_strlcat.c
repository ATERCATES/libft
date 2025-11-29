/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 01:56:38 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/15 21:02:55 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	lendst = 0;
	while (dst[lendst] && lendst < dstsize)
		lendst++;
	lensrc = ft_strlen(src);
	if (lendst == dstsize)
		return (dstsize + lensrc);
	i = 0;
	while (src[i] && lendst + i + 1 < dstsize)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}
