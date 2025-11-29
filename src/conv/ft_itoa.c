/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:09:53 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/22 20:13:40 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(long n)
{
	int	i;

	i = 2;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fill_str(char *result, long n, int p)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
	{
		result[p] = (char)(n % 10 + '0');
		fill_str(result, n / 10, p - 1);
	}
	if (n < 10)
		result[p] = (char)(n + '0');
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	long	nb;

	nb = n;
	size = get_length(nb);
	result = malloc(size * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[size - 1] = '\0';
	if (n < 0)
		result[0] = '-';
	fill_str(result, nb, size - 2);
	return (result);
}
