/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:13:40 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/08 16:33:34 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	s2b = (unsigned char *)s2;
	s1b = (unsigned char *)s1;
	i = 0;
	while (i < n)
	{
		if (s2b[i] != s1b[i])
			return (s1b[i] - s2b[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1b[i] - s2b[i]);
}
