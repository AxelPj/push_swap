/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:54:51 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/07 19:10:21 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	j = 0;
	i = 0;
	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1 && s1[i])
		s[k++] = s1[i++];
	while (s2 && s2[j])
		s[k++] = s2[j++];
	s[k] = '\0';
	return (free(s1), s);
}
