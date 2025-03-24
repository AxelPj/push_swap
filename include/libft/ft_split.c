/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:07:55 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/07 19:15:36 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*place_word(const char *str, size_t start, size_t end)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = malloc(((end - start) + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (start <= end)
	{
		tab[i] = str[start];
		start++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char	**ft_free(char **tab, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;
	size_t	start;

	i = 0;
	j = 0;
	tab = (char **)malloc((count_word (s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (j < count_word(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = place_word(s, start, i - 1);
		if (!tab[j])
			return (ft_free(tab, j));
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
