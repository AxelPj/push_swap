/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:16:15 by axel              #+#    #+#             */
/*   Updated: 2025/03/19 15:17:46 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long    ft_atol(const char *str)
{
	size_t		i;
	long		result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10 + (str[i] - 48));
		i++;
	}
	return (result * sign);
}
