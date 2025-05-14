/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:23:24 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/11 18:04:40 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
{
	int	resultado;
	int	sign;

	resultado = 0;
	sign = 1;
	while (*str <= ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		resultado = resultado * 10 + (int)*str - '0';
		str++;
	}
	return (resultado * sign);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str = "    +12313";
	int	result;

	result = ft_atoi(str);
	printf("El número final es %d", result);
	return (0);
}*/
