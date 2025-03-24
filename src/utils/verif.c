/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:51:57 by axel              #+#    #+#             */
/*   Updated: 2025/03/21 18:07:12 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

int verif_all(int argc, char **argv)
{	
	if (verif_nb(argc, argv) == 1 || verif_limit(argc, argv) == 1)
		return (1);
	else
		return (0);
}

int verif_nb(int argc, char **argv)
{
	int i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while(argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int verif_limit(int argc, char **argv)
{
	long	nb;
	int	j;

	j = 1;
	while (j < argc)
	{
		nb = ft_atol(argv[j]);
		if (nb > 2147483647 || nb < -2147483648)
			return (1);
		j++;
	}
	return (0);
}