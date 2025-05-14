/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:25:03 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/12 11:53:01 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*nstr;

	start = 0;
	while (ft_strchr(set, s1[start]) != NULL)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	nstr = malloc(end - start + 1);
	if (nstr == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		nstr[i] = s1[start];
		i++;
		start++;
	}
	nstr[i] = '\0';
	return (nstr);
}
