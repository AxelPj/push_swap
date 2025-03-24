/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:29:23 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/07 19:03:40 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			i;
	unsigned char	val;

	val = (unsigned char)c;
	i = 0;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		s2[i] = val;
		i++;
	}
	return (s);
}
