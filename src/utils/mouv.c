/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:32:52 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/23 19:08:30 by axelpeti         ###   ########.fr       */
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
		sa(&data_lst->a);
	else if (first > second && second > third)
	{
		sa(&data_lst->a);
		rra(&data_lst->a);
	}
	else if (first > second && second < third && first > third)
		ra(&data_lst->a);

	else if (first < second && second > third && first < third)
	{
		sa(&data_lst->a);
		ra(&data_lst->a);
	}
	else if (first < second && second > third && first > third)
		rra(&data_lst->a);
}

void	sort_b(t_data *data_lst)
{
	if (data_lst->index_big_b <= data_lst->size_b / 2)
		data_lst->cost_b = data_lst->index_big_b;
	else
		data_lst->cost_b = -(data_lst->size_b - data_lst->index_big_b);
	mouv_b(data_lst);
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

void	mouv_all(t_data *data_lst)
{
	pb(&data_lst->a, &data_lst->b);
	pb(&data_lst->a, &data_lst->b);
	reinit_data(data_lst);
	printf("size = %d\n", data_lst->size_a);
	print_lst(data_lst);
	while (data_lst->size_a > 3)
	{
		printf("\n");
		printf("small b = %d", data_lst->small_b);
		printf("\n");
		printf("big b = %d", data_lst->biggest_b);
		printf("\n");
		check_place(data_lst);
		if ((data_lst->cost_a > 0 && data_lst->cost_b > 0) 
			|| (data_lst->cost_a < 0 && data_lst->cost_b < 0))
			mouv_combined(data_lst);
		else
		{
			mouv_a(data_lst);
			mouv_b(data_lst);
		}
		pb(&data_lst->a, &data_lst->b);
		printf("\n");
		// printf("\n");
		reinit_data(data_lst);
		print_lst(data_lst);
	}
	sort_three(data_lst);
	print_lst(data_lst);
	sort_b(data_lst);
	print_lst(data_lst);
	printf("\n");
	push_to_stack_a(data_lst);
	push_to_stack_a(data_lst);
	printf ("\n");
	print_lst(data_lst);
}

int	verif_place_a(t_data *data_lst, int x)
{
	t_list *current = data_lst->a;

	if (!current)
		return (1);
	if (x < current->content)
        return (1);
	while (current && current->next)
	{
		if (current->content < x && x < current->next->content)
            return 1;
        current = current->next;
	}
	if (x > current->content)
		return (1);
	return(0);
}
void push_to_stack_a(t_data *data_lst)
{
	t_list *current;

	current = data_lst->b;
	while (current)
	{
    	while (!verif_place_a(data_lst, current->content)) 
    	{
    	    if (data_lst->a->content > data_lst->b->content)
    	        rra(&data_lst->a); 
    	    else
    	        ra(&data_lst->a); 
    	}
    	pa(&data_lst->a, &data_lst->b);
		current = current->next;
	}
}