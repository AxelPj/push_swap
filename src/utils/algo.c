/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:34:34 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/23 18:33:17 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

void	cost_mouv_stack(t_data *data_lst, int index_a, int index_b)
{
	if (index_a <= data_lst->size_a / 2)
		data_lst->temp_cost_a = index_a;
	else
		data_lst->temp_cost_a = -(data_lst->size_a - index_a);
	if (index_b <= data_lst->size_b / 2)
		data_lst->temp_cost_b = index_b;
	else
		data_lst->temp_cost_b = -(data_lst->size_b - index_b);
	if ((data_lst->cost_a >= 0 && data_lst->cost_b >= 0)
		|| (data_lst->cost_a <= 0 && data_lst->cost_b <= 0))
	{
		if (abs(data_lst->temp_cost_a) > abs(data_lst->temp_cost_b))
			data_lst->temp_cost_total = abs(data_lst->temp_cost_a);
		else
			data_lst->temp_cost_total = abs(data_lst->temp_cost_b);
	}
	else 
		data_lst->temp_cost_total = abs(data_lst->temp_cost_a)
			+ abs(data_lst->temp_cost_b);
	if ((data_lst->temp_cost_total < data_lst->total_cost) || data_lst->total_cost == 1000)
	{
		data_lst->total_cost = data_lst->temp_cost_total;
		data_lst->index_a = index_a;
		data_lst->index_b = index_b;
		data_lst->cost_a = data_lst->temp_cost_a;
		data_lst->cost_b = data_lst->temp_cost_b;
		printf("index b= %d index a = %d\n", data_lst->index_b, data_lst->index_a);
		printf("temp b= %d temp a = %d\n", abs(data_lst->temp_cost_b), abs(data_lst->temp_cost_a));
		printf("total cost = %d\n", data_lst->total_cost);
		printf("\n");
	}
}

void	check_place(t_data *data_lst)
{
	t_list	*current;
	int	index_temp;

	index_temp = 0;
	current = data_lst->a;
	while (current)
	{
		if (current->content < data_lst->small_b)
		{
			cost_mouv_stack(data_lst, current->index, data_lst->a->index);
 			/* printf ("\n\ncontent small = %d\n\n", current->content);	 */	
		}
		else if(current->content > data_lst->biggest_b)
		{
			cost_mouv_stack(data_lst, current->index, data_lst->index_big_b);
/* 			printf ("\n\ncontent big = %d\n\n", current->content);
 */		}
		else if (find_insert_pos(data_lst->b, current->content) != -1)
		{
			index_temp = find_insert_pos(data_lst->b, current->content);
/* 			printf ("\n\ncontent insert = %d\n\n", current->content);
 */			cost_mouv_stack(data_lst, current->index, index_temp);
		}
		current = current->next;
	}
}

void	find_small_and_big_nb(t_data *data_lst)
{
	t_list	*current;

	current = data_lst->b;
	data_lst->small_b = current->content;
	data_lst->biggest_b = current->content;
	while (current)
	{
		if (current->content < data_lst->small_b)
		{
			data_lst->small_b = current->content;
			data_lst->index_small_b = current->index;
		}
		else if (current->content > data_lst->biggest_b)
		{
			data_lst->biggest_b = current->content;
			data_lst->index_big_b = current->index;
		}
		current = current->next;
	}
}

int	find_insert_pos(t_list *stack, int x)
{
	t_list	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->content > x && x > current->next->content)
			return (current->next->index);
		current = current->next;
	}
	return (-1);
}
