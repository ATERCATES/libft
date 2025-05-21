/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javifer2 <javifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:53:34 by javifer2          #+#    #+#             */
/*   Updated: 2025/05/21 20:31:48 by javifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct positions
{
	int					*start;
	int					*end;
	struct positions	*next;
}						t_pos;

void	ft_clean_lst(t_pos	**lst)
{
	t_pos	current;
	t_pos	next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		if (current->start)
			free(current->start);
		if (current->end)
			free(current->end);
		free(current);
		current = next;
	}
	*lst = NULL;
}


static t_pos	*add_lst_after(t_pos **lst, int start, int end)
{
	t_pos	*new_node;
	t_pos	*current;

	if (!lst)
		return (NULL);
	new_node = malloc(sizeof(t_pos));
	if (!new_node)
		return (NULL);
	new_node->start = start;
	new_node->end = end;
	new_node->next = NULL;
	if (*lst == NULL)
	{
		*lst = new_node;
		return (new_node);
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (new_node);
}

t_pos	**get_locations(t_pos **lst, char  const *s, char c)
{
	t_pos	*current;
	int	i;
	int	start;
	int	in_word;

	i = 0;
	in_word = 0;
	start = 0;
	lst = malloc(sizeof(t_pos));
	while (s[i])
	{
		if (s[i] == c && in_word)
		{
			current = add_lst_after(lst, start, i);
			if (!current)
				return (NULL);
		}
		elif (s[i] != c && !in_word)
		{
			in_word = 1;
			start = i;
		}
		s++;
	}
	return (lst);
}

void	fill_str(char *result; char const *s, int start, int end)
{
	while (s[start])
}

char	**ft_split(char const *s, char c)
{
	t_pos	**lst;
	t_pos	*current;
	char	**result;

	result = malloc(sizeof(char *));
	lst = get_locations(lst, s, c);
	if (!lst)
		return (NULL);
	current = *lst;
	while (current)
	{
		
	}
}

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
	{
		free(result);
 		return (0);
	}
	free(result);
 	return (1);
}
/*
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
