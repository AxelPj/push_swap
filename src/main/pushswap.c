/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:45:33 by axel              #+#    #+#             */
/*   Updated: 2025/04/25 18:33:45 by axelpeti         ###   ########.fr       */
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
		printf ("\n\ntab arg ok\n\n");
		if (verif_all(tab_arg) == 0)
		{
			data_lst = init(tab_arg, data_lst);
			printf ("\n\ndata list ok\n\n");
			mouv_a_to_b(data_lst);
			printf ("\n\nmouv a to b\n\n");
			sort_three(data_lst);
			mouv_b_to_a(data_lst);
		}
	}
	else
		write (2, "error", 5);
}
