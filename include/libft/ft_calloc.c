/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:53:13 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/07 18:54:24 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nmemb, int size)
{
	void			*tab;
	size_t			total_size;
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	total_size = (size_t)nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tab = malloc(total_size);
	if (!tab)
		return (NULL);
	ptr = (unsigned char *)tab;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (tab);
}
