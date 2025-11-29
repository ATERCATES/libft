/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:32:01 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/21 20:51:08 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	error_clean(char **result, int arr)
{
	while (arr >= 0)
	{
		free(result[arr]);
		arr--;
	}
	free(result);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*allocate_word(char const *s, int start, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static int	process_words(char const *s, char c, char **result, int words)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		result[j] = allocate_word(s, start, i - start);
		if (!result[j])
		{
			error_clean(result, j - 1);
			return (0);
		}
		j++;
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (!process_words(s, c, result, words))
		return (NULL);
	return (result);
}
