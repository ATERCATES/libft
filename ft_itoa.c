/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:09:53 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/13 20:58:42 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <libft.h>*/
#include <stdio.h>
#include <stdlib.h>

int	get_length(int n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 2);
}

void	fill_str(char *result, int n, int p)
{
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
	
	size = get_length(n);
	result = malloc(size * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[size - 1] = '\0';
	fill_str(result, n, size - 2);
	return (result);
}

int	main(int argc, char **argv)
{
	int	length;
	char  *result;

	if (argc != 2)
		printf("Parametro invalido. Uso %s 'NUM'", argv[0]);
		return (1);
	length = get_length(argv[1]);
	printf("Reservando %d bytes de memoria para %d\n", length, argv[1]);
	result = ft_itoa(argv[1]);
	printf("La string resultante es %s\n", result);
	free(result);
	return (0);
}



