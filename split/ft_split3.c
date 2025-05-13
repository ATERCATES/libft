/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:53:34 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/13 18:16:24 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <libft.h>*/
#include <stdlib.h>
#include <stdio.h>

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

int	get_str(char const *s, char c)
{
	int	in_word;
	int	counter;

	in_word = 1;
	counter = 0;
	while (*s != '\0')
	{
		if (*s != c && !in_word)
			in_word = 1;
		else if (*s == c)
		{
			counter++;
			in_word = 0;
		}
		s++;
	}
	if (in_word)
		counter++;
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int	strs;
	int	str;
	int	start;
	int	end;
	int	in_word;

	strs = get_str(s, c);
	result = malloc(strs * sizeof(char *));
	if (result == NULL)
		return (NULL);
	start = 0;
	end = 0;
	in_word = 0;
	str = 0;
	while (s[end])
	{
		while (s[end] && s[end] != c)
		{
			in_word = 1;
			end++;
		}
		if ((s[end] == '\0' || (s[end] == c && in_word)) && end != start)
		{
			result[str] = malloc((end - start + 1) * sizeof(char));
			if (result[str] == NULL)
			{
				error_clean(result, str);
				return (NULL);
			}
			fill_str(s, result[str], start, end);
			start = end;
			in_word = 0;
		}
		if (s[end + 1] != '\0' && !in_word)
			end++;
	}
	return (result);
}


int	main(int argc, char **argv)
{
	int	i;
	char	**result;

	if (argc != 3)
	{
		printf("Parámetros incorrectos! Uso: %s 'cadena' 'separador'", argv[0]);
		return (1);
	}
	/*printf("Separando %s: con %c", argv[1], argv[2][0]);*/
	result = ft_split(argv[1], argv[2][0]);
	i = 0;
	while (result[i])
		printf("Cadena %d: %s", i, result[i]);
	return (0);
}
