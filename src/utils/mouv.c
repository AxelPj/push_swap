/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:32:52 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/26 21:33:36 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

void	mouv_a(t_data *data_lst)
{
	if (data_lst->cost_a < 0)
	{
		while (data_lst->cost_a <= 0)
		{
			rra(&data_lst->a, 0);
			data_lst->cost_a++;
		}
	}
	else
		while (data_lst->cost_a >= 0)
		{
			ra(&data_lst->a, 0);
			data_lst->cost_a--;
		}
}

void	mouv_b(t_data *data_lst)
{
	if (data_lst->cost_b < 0)
		while (data_lst->cost_b <= 0)
		{
			rrb(&data_lst->b, 0);
			data_lst->cost_b++;
		}
	else
		while (data_lst->cost_b >= 0)
		{
			rb(&data_lst->b, 0);
			data_lst->cost_b--;
		}
}

void	mouv_combined(t_data *data_lst)
{
	while (data_lst->cost_a > 0 && data_lst->cost_b > 0)
	{
		rr(&data_lst->a, &data_lst->b);
		data_lst->cost_a--;
		data_lst->cost_b--;
	}
	while (data_lst->cost_a < 0 && data_lst->cost_b < 0)
	{
		rrr(&data_lst->a, &data_lst->b);
		data_lst->cost_a++;
		data_lst->cost_b++;
	}
}

void	sort_three(t_data *data_lst)
{
	int	first = data_lst->a->content;
	int	second = data_lst->a->next->content;
	int	third = data_lst->a->next->next->content;

	if (first < second && second < third)
		return ;
	else if (first > second && second < third && first < third)
		sa(&data_lst->a, 0);
	else if (first > second && second > third)
	{
		sa(&data_lst->a, 0);
		rra(&data_lst->a, 0);
	}
	else if (first > second && second < third && first > third)
		ra(&data_lst->a, 0);

	else if (first < second && second > third && first < third)
	{
		sa(&data_lst->a, 0);
		ra(&data_lst->a, 0);
	}
	else if (first < second && second > third && first > third)
		rra(&data_lst->a, 0);
}

int	verif_sort(t_list *stack)
{
	t_list	*current;
	
	current = stack;
	while (current)
	{
		if (current->next && current->content > current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
}

void	mouv_a_to_b(t_data *data_lst)
{
	pb(&data_lst->a, &data_lst->b);
	pb(&data_lst->a, &data_lst->b);
	reinit_data(data_lst, data_lst->b);
	find_small_and_big_nb(data_lst, data_lst->b);
	if (data_lst->size_a > 3)
	{
		while (data_lst->size_a > 4)
		{
			reinit_data(data_lst, data_lst->b);
			update_indexes(data_lst->a, data_lst->b);
			find_small_and_big_nb(data_lst, data_lst->b);
			check_place_a_to_b (data_lst);
			if ((data_lst->cost_a > 0 && data_lst->cost_b > 0) 
				|| (data_lst->cost_a < 0 && data_lst->cost_b < 0))
				mouv_combined(data_lst);
			else
			{
				mouv_a(data_lst);
				mouv_b(data_lst);
			}
			pb(&data_lst->a, &data_lst->b);
		}	
	}
}

void	mouv_b_to_a(t_data *data_lst)
{
	while (data_lst->size_b > 0)
	{
		reinit_data(data_lst, data_lst->a);
		update_indexes(data_lst->a, data_lst->b);
		find_small_and_big_nb(data_lst, data_lst->a);
		check_place_b_to_a(data_lst);
		if ((data_lst->cost_a > 0 && data_lst->cost_b > 0) 
			|| (data_lst->cost_a < 0 && data_lst->cost_b < 0))
			mouv_combined(data_lst);
		else
		{
			mouv_a(data_lst);
			mouv_b(data_lst);
		}
		pa(&data_lst->a, &data_lst->b);
	}
}

void	check_place_b_to_a(t_data *data_lst)
{
	t_list	*current;
	int	index_temp;

	index_temp = 0;
	current = data_lst->b;
	while (current)
	{
		if (current->content < data_lst->small_nb)
		{
			cost_mouv_stack(data_lst, data_lst->index_small_nb, current->index);
		}
		else if(current->content > data_lst->biggest_nb)
		{
			if (data_lst->index_big_nb == data_lst->size_a - 1)
				cost_mouv_stack(data_lst, data_lst->a->index, current->index);
			else
				cost_mouv_stack(data_lst, data_lst->index_big_nb + 1, current->index);
		}
		else if (find_insert_pos_b_to_a(data_lst->a, current->content) != -1)
		{
			index_temp = find_insert_pos_b_to_a(data_lst->a, current->content);
			cost_mouv_stack(data_lst, index_temp, current->index);
		}
		current = current->next;
	}
}
void	sort_a(t_data *data_lst)
{
	reinit_data(data_lst, data_lst->a);
	if (data_lst->index_small_nb <= data_lst->size_a / 2)
	{
		data_lst->cost_a = data_lst->index_small_nb;
		mouv_a(data_lst);
	}
	else
	{
		data_lst->cost_a = -(data_lst->size_a - data_lst->index_small_nb);
		mouv_a(data_lst);
	}
}
