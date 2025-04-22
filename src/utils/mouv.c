/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:32:52 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/22 18:55:20 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

void	mouv_a(t_data *data_lst)
{
	if (data_lst->cost_a < 0)
	{
		while (data_lst->cost_a < 0)
		{
			rra(&data_lst->a);
			data_lst->cost_a++;
		}
	}
	else
		while (data_lst->cost_a > 0)
		{
			ra(&data_lst->a);
			data_lst->cost_a--;
		}
}

void	mouv_b(t_data *data_lst)
{
	if (data_lst->cost_b < 0)
		while (data_lst->cost_b < 0)
		{
			rrb(&data_lst->b);
			data_lst->cost_b++;
		}
	else
		while (data_lst->cost_b > 0)
		{
			rb(&data_lst->b);
			data_lst->cost_b--;
		}
}

void	mouv_all(t_data *data_lst)
{
	pb(&data_lst->a, &data_lst->b);
	pb(&data_lst->a, &data_lst->b);
	reinit_data(data_lst);
	printf("size = %d\n", data_lst->size_a);
	print_lst(data_lst->b);
	while (data_lst->size_a > 0)
	{
		/* printf("\n");
		printf("small b = %d", data_lst->small_b);
		printf("\n");
		printf("big b = %d", data_lst->biggest_b);
		printf("cost = a : %d b: %d\n", data_lst->cost_a, data_lst->cost_b); */
		check_place(data_lst);
		mouv_a(data_lst);
		mouv_b(data_lst);
		pb(&data_lst->a, &data_lst->b);
		printf("\n");
		print_lst(data_lst->b);
		// printf("\n");
		reinit_data(data_lst);
	}
}
