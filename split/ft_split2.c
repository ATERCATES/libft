/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:53:34 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/12 18:41:00 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	error_clean(char **result, int arr)
{
	while (arr >= 0)
	{
		free(result[arr]);
		arr--;
	}
	free(result);
}

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
	result[i] = '\0';
}

int	count_str(char *s, char c)
{
	int	counter;
	int	in_word;

	counter = 0;
	in_word = 1;
	while (*s != '\0')
	{
		if (*s != c && !in_word)
		{
			counter++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	if (in_word)
		counter++;
	return (counter + 1);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	int	str;
	int	in_word;
	char	**result;

	result = malloc(count_str(s, c) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	str = 0;
	i = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		j = i;
		while (s[i] && s[i] != c)
		{
			i++;
			in_word = 1;
		}
		if ((s[i] == c || s[i] == '\0') && in_word)
		{
			result[str] = malloc((i - j + 1) * sizeof(char));
			if (result[str] == NULL)
			{
				error_clean(result, str);
				return (NULL);
			}
			fill_str(s, result[str], j, i);
			str++;
			in_word = 0;
		}
		i++;
	}
	result[str] = NULL;
	return (result);
}
