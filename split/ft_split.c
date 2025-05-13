/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:53:34 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/12 12:28:58 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	fill_str(char const *s, char *result, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		result[i] = s[start];
		i++;
		start++;
	}
}

int	get_buffer_size(char const *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			counter++;
		i++;
	}
	return (ft_strlen(s) - counter + 1);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	int	str;
	char	**result;

	result = malloc(get_buffer_size(s, c));
	if (result == NULL)
		return (NULL);
	str = 0;
	i = 0;
	while (s[i] != '\0')
	{
		j = i;
		while (s[i] != c)
		{
			i++;
		}
		fill_str(s, result[str], j, i);
		i++;
		str++;
	}
	result[str] = NULL;
	return (result);
}
