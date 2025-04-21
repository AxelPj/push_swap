/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:34:34 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/21 18:41:02 by axelpeti         ###   ########.fr       */
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
	data_lst->temp_cost_total = abs(data_lst->temp_cost_a)
		+ abs(data_lst->temp_cost_b);
	if (data_lst->temp_cost_total < data_lst->total_cost)
	{
		data_lst->total_cost = data_lst->temp_cost_total;
		data_lst->index_a = index_a;
		data_lst->index_b = index_b;
		data_lst->cost_a = data_lst->temp_cost_a;
		data_lst->cost_b = data_lst->temp_cost_b;
	}
}

void	check_place(t_data *data_lst)
{
	t_list	*current;
	int		index_temp;

	find_small_and_big_nb(data_lst);
	current = data_lst->a;
	while (current)
	{
		if (current->content < data_lst->small_b)
			cost_mouv_stack(data_lst, current->index, data_lst->index_small_b);
		else if (current->content > data_lst->biggest_b)
			cost_mouv_stack(data_lst, current->index, data_lst->index_big_b);
		else
		{
			index_temp = find_insert_pos(data_lst->b, current->content);
			cost_mouv_stack(data_lst, current->index, index_temp);
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
	while (current->next)
	{
		if (data_lst->index_small_b > current->content)
		{
			data_lst->small_b = current->content;
			data_lst->index_small_b = current->index;
		}
		if (data_lst->biggest_b > current->content)
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
	int		index;

	index = 0;
	current = stack;
	while (current->next)
	{
		if (current->content < x && x < current->next->content)
			return (current->next->index);
		current = current->next;
	}
	return (current->next->index);
}
