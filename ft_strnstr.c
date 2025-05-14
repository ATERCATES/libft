/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:52:37 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/11 17:09:06 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	back;

	i = 0;
	if (!needle[i])
		return (haystack);
	while (i < len)
	{
		back = i;
		j = 0;
		while (i < len && haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (haystack + back);
		i = back + 1;
	}
	return (NULL);
}
