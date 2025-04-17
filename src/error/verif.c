/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:51:57 by axel              #+#    #+#             */
/*   Updated: 2025/04/17 17:44:15 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

char **arg_to_tab(char **av, int ac)
{
	char *str;
	char **tab_arg;
	int	i;

	i = 1;
	tab_arg = NULL;
	str = ft_strdup(" ");
	if (ac == 2)
		str = ft_strjoin(str, av[1]);
	else
	{
		while (i < ac)
		{
			str = ft_strjoin(str, " ");
			str = ft_strjoin(str, av[i]);
			i++;
		}
	}
	tab_arg = ft_split(str, ' ');
	return (tab_arg);
}

int verif_all(char **tab)
{	
	if (verif_nb(tab) == 0)
	{
		if (verif_limit(tab) == 0 && verif_duplicate(tab, 0, 0) == 0)
			return (0);
	}
	return (write (2, "error\n", 6), 1);
}

int verif_nb(char **tab_arg)
{
	int i;
	int	j;

	i = 0;
	while (tab_arg[i])
	{
		j = 0;
		while (tab_arg[i][j])
		{
			if (tab_arg[i][0] == '-' && tab_arg[i][1])
				j++;
			if ((tab_arg[i][j] && tab_arg[i][j] < '0') 
				|| (tab_arg[i][j] && tab_arg[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verif_limit(char **tab)
{
	long	nb;
	int		j;

	j = 1;
	while (tab[j])
	{
		nb = ft_atol(tab[j]);
		if (nb > 2147483647 || nb < -2147483648)
			return (1);
		j++;
	}
	return (0);
}

int	verif_duplicate(char **tab_arg, int i, int j)
{
	int	*tab_nb;
	int max;

	max = tablen((void **) tab_arg);
	tab_nb = malloc(max * sizeof(int));
	while (tab_arg[i] != NULL)
	{
		tab_nb[i] = ft_atol(tab_arg[i]);
		i++;
	}
	while (j < max)
	{
		i = j + 1;
		while (tab_nb[i])
		{
			if (tab_nb[j] == tab_nb[i])
				return (1);
			i++;
		}
		j++;
	}
	if (j == 1)
		return (1);
	return (0);
}
