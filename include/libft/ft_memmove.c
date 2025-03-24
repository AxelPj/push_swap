/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:57:48 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/09 12:19:49 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memmove_right(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src2;
	unsigned char		*dest2;

	src2 = (const unsigned char *) src;
	dest2 = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}

static void	*ft_memmove_left(void *dest, const void *src, size_t n)
{
	const unsigned char	*src2;
	unsigned char		*dest2;

	src2 = (const unsigned char *) src;
	dest2 = (unsigned char *) dest;
	while (n > 0)
	{
		n--;
		dest2[n] = src2[n];
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		ft_memmove_right (dest, src, n);
	else
		ft_memmove_left (dest, src, n);
	return (dest);
}
