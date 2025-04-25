/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:34:34 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/25 18:30:33 by axelpeti         ###   ########.fr       */
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
	if ((data_lst->temp_cost_a < 0 && data_lst->temp_cost_b < 0) 
		|| (data_lst->temp_cost_a > 0 && data_lst->temp_cost_b > 0))
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
	}
}

void	check_place_a_to_b(t_data *data_lst)
{
	t_list	*current;
	int	index_temp;

	index_temp = 0;
	current = data_lst->a;
	while (current)
	{
		if (current->content < data_lst->small_nb)
		{
			if(data_lst->index_small_nb == data_lst->size_b - 1)
				cost_mouv_stack(data_lst, current->index, data_lst->b->index);
			else
				cost_mouv_stack(data_lst, current->index, data_lst->index_small_nb);
		}
		else if(current->content > data_lst->biggest_nb)
		{
			cost_mouv_stack(data_lst, current->index, data_lst->index_big_nb);
		}
		else if (find_insert_pos_a_to_b(data_lst->b, current->content) != -1)
		{
			index_temp = find_insert_pos_a_to_b(data_lst->b, current->content);
			cost_mouv_stack(data_lst, current->index, index_temp);
		}
		current = current->next;
	}
}

void	find_small_and_big_nb(t_data *data_lst, t_list *stack)
{
	t_list	*current;
	int		size;

	size = ft_lstsize (stack);
	current = stack;
	data_lst->small_nb = current->content;
	data_lst->index_small_nb = current->index;
	data_lst->biggest_nb = current->content;
	data_lst->index_big_nb = current->index;
	while (current)
	{
		if (current->content < data_lst->small_nb)
		{
			data_lst->small_nb = current->content;
			data_lst->index_small_nb = current->index;
			printf ("\n\nsmall = %d index = %d\n\n", current->content, current->index);
		}
		else if (current->content > data_lst->biggest_nb)
		{
			data_lst->biggest_nb = current->content;
			data_lst->index_big_nb = current->index;
			printf ("\n\nbig = %d index = %d\n\n", current->content, current->index);
		}
		current = current->next;
	}
}

int	find_insert_pos_a_to_b(t_list *stack, int x)
{
	t_list	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->content > x && x > current->next->content)
			return (current->next->index);
		current = current->next;
	}
	if (current->content > x && x > stack->content)
		return (current->index);
	return (-1);
}

int	find_insert_pos_b_to_a(t_list *stack, int x)
{
	t_list	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->content < x && x < current->next->content)
			return (current->next->index);
		current = current->next;
	}
	if (current->content < x && x < stack->content)
		return (stack->index);
	return (-1);
}
