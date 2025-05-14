/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:04:29 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/14 20:11:17 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	length;

	if (!s || !f)
		return ;
	length = ft_strlen(s);
	i = 0;
	while (i < length)
	{
		f(i, &s[i]);
		i++;
	}
}
