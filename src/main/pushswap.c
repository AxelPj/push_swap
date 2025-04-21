/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:45:33 by axel              #+#    #+#             */
/*   Updated: 2025/04/21 18:25:49 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

int	main(int ac, char **av)
{
	t_data	*data_lst;
	char	**tab_arg;
	int		i;

	i = 0;
	data_lst = NULL;
	if (ac > 1)
	{
		tab_arg = arg_to_tab(av, ac);
		if (verif_all(tab_arg) == 0)
		{
			data_lst = init(tab_arg, data_lst);
			print_lst(data_lst->a);
			mouv_all(data_lst);
			printf("\nstack a =\n");
			print_lst(data_lst->a);
			printf("\nstack b =\n");
			print_lst(data_lst->b);
		}
	}
	else
		write (2, "error", 5);
}
