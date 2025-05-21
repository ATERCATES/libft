/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:47:49 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/21 19:04:44 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_f(void	*content)
{
	char	*ptrcontent;
	char	*result;
	int		i;

	if (!content)
		return (NULL);
	ptrcontent = (char *)content;
	result = strdup(ptrcontent);
	if (!result)
		return (NULL);
	i = 0;
	while (result[i])
	{
		if (result[i] >= 'a' && result[i] <= 'z')
		{
			result[i] = result[i] - 32;
		}
		i++;
	}
	return (result);
}
