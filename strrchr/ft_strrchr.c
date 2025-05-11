/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:15:46 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/11 03:37:37 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*strrchr(const char *s, int c)
{
	char	*pt;

    	if (c == '\0')
        	return ((char *)s + strlen(s));
	pt = NULL;
	while (*s)
	{
		if (*s == (char)c)
			pt = (char *)s;
		s++;
	}
	return (pt);
}
