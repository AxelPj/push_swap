/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:45:33 by axel              #+#    #+#             */
/*   Updated: 2025/04/26 20:49:48 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

int	main(int ac, char **av)
{
	t_data	*data_lst;
	char	**tab_arg;

	data_lst = NULL;
	if (ac > 1)
	{
		tab_arg = arg_to_tab(av, ac);
		if (verif_all(tab_arg) == 0)
		{
			data_lst = init(tab_arg, data_lst);
			if (data_lst->size_a == 1)
				return (2);
			else if (data_lst->size_a == 3)
				sort_three(data_lst);
			else
			{
				mouv_a_to_b(data_lst);
				sort_three(data_lst);
				mouv_b_to_a(data_lst);
				sort_a(data_lst);
				print_lst(data_lst);
			}
		}
	}
	else
		write (2, "error", 5);
}
