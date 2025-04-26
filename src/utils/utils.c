/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:29:46 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/26 21:05:09 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

int	check_sort_lst(t_list **stack_a)
{
	t_list	*current;
	int		temp;

	temp = 0;
	current = *stack_a;
	while (current->next)
	{
		if (current->content < current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
}

void	update_indexes(t_list *stack_push, t_list *stack_receive)
{
	int		i;
	t_list	*current;

	i = 0;
	current = stack_push;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
	current = stack_receive;
	i = 0;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}


void	reinit_data(t_data *data_lst, t_list *stack_receive)
{
	(void) stack_receive;
	data_lst->size_a = ft_lstsize(data_lst->a);
	data_lst->size_b = ft_lstsize(data_lst->b);
	data_lst->total_cost = 1000;
}

void	print_lst(t_data *data_lst)
{
	t_list	*current_b;
	t_list *current_a;
	
	current_a = data_lst->a;
	current_b = data_lst->b;
	printf("\n");
	if (ft_lstsize(data_lst->a) >= ft_lstsize(data_lst->b))
	{
		while (current_a)
		{
			printf ("%d", current_a->content);
			printf(" | ");
			if (current_b)
			{
				printf ("%d", current_b->content);
				current_b = current_b->next;
			}
			printf("\n");
			current_a = current_a->next;
		}
	}
	else if (ft_lstsize(data_lst->a) < ft_lstsize(data_lst->b))
	{
		while (current_b)
		{
			if (current_a)
			{
				printf ("%d", current_a->content);
				current_a = current_a->next;
			}
			printf(" | ");
			printf ("%d", current_b->content);
			printf("\n");
			current_b = current_b->next;
		}
	}
}
