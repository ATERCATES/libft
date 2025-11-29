/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:43:49 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/22 20:40:21 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	slength;

	i = 0;
	if (!s)
		return (NULL);
	slength = ft_strlen(s);
	if (start >= slength)
		len = 0;
	if (len > slength - start)
		len = slength - start;
	newstr = malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (i < len && s[start + i])
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
