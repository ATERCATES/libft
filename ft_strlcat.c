/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 01:56:38 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/11 02:26:43 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	i = 0;
	lendst = 0;
	while (dst[lendst] && lendst < dstsize)
		lendst++;
	lensrc = ft_strlen(src);
	if (lendst == dstsize)
		return (dstsize + lensrc);
	while (src[i] && lendst < dstsize - 1)
	{
		dst[lendst] = src[i];
		i++;
		lendst++;
	}
	dst[lendst] = '\0';
	return ((lendst - i) + lensrc);
}
