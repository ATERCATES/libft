/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 01:56:38 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/15 19:33:43 by javifer2         ###   ########.fr       */
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
	while (src[i] && lendst < dstsize - 1)
	{
		dst[lendst] = src[i];
		i++;
		lendst++;
	}
	dst[lendst] = '\0';
	return (lendst + lensrc);
}

/*
int	main(void)
{
	char	*src = "Mundo!";
	char	dst[12] = "Hola ";
	size_t	trunc;

	trunc = strlcat(dst, src, sizeof(dst));
	printf("String resultante: %s, tamano esperado %ld, tamano recibido: %ld", dst, ft_strlen(src) + sizeof(dst), trunc);
	return (0);
}*/
