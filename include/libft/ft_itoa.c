/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:47:24 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/07 18:55:29 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static void	print_result(size_t len, size_t i, long nb, char *result)
{
	while (len > i)
	{
		result[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*result;
	size_t	len;
	long	nb;

	i = 0;
	nb = (long) n;
	len = count_len (nb);
	result = malloc((len + 1) * sizeof (char));
	if (!result)
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		i = 1;
		nb = -nb;
	}
	print_result(len, i, nb, result);
	result[len] = '\0';
	return (result);
}
