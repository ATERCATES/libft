/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:53:34 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/20 17:48:18 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	error_clean(char **result, int arr)
{
	while (arr >= 0)
	{
		free(result[arr]);
		arr--;
	}
	free(result);
}

static void	fill_str(char const *s, char *result, int start, int end)
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

static char	**get_str_memory(char const *s, char c)
{
	int		in_word;
	int		counter;
	char	**result;

	in_word = 0;
	counter = 0;
	while (*s != '\0')
	{
		if (*s != c && !in_word)
			in_word = 1;
		else if (*s == c && in_word)
		{
			counter++;
			in_word = 0;
		}
		s++;
	}
	if (in_word)
		counter++;
	result = malloc((counter + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	return (result);
}

static char	*allocate_fill(char **result, int str, int size)
{
	result[str] = malloc((size + 1) * sizeof(char));
	if (result[str] == NULL)
	{
		error_clean(result, str);
		return (NULL);
	}
	return (result[str]);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		str;
	int		start;
	int		end;

	start = 0;
	end = 0;
	str = 0;
	result = get_str_memory(s, c);
	while (s && s[end] && result != NULL)
	{
		while (s[end] && s[end] != c)
			end++;
		if ((s[end] == c || s[end] == '\0') && end - start != 0)
		{
			result[str] = allocate_fill(result, str, end - start);
			fill_str(s, result[str], start, end);
			str++;
		}
		while (s[end] == c)
			end++;
		start = end;
	}
	result[str] = NULL;
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char *s = "      split       this for   me  !       ";
	printf("Cadena original: '%s'\n", s);

	char **result = ft_split(s, ' ');
	printf("Cadena separada:\n");
	for (int i = 0; result[i] != NULL; i++)
	{
		printf("Cadena %d: '%s'\n", i, result[i]);
		free(result[i]);
	}
	if (!result)
 		return (0);
 	return (1);
	free(result);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	int		i;
	char	**result;

	if (argc != 3)
	{
		printf("Parámetros incorrectos! Uso: %s 'cadena' 'separador'", argv[0]);
		return (1);
	}
	result = ft_split(argv[1], argv[2][0]);
	i = 0;
	while (result[i])
	{
		printf("Cadena %d: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free (result);
	return (0);
}*/
