/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:29:46 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/21 18:41:13 by axelpeti         ###   ########.fr       */
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

void	update_indexes(t_list *a, t_list *b)
{
	int		i;
	t_list	*current;

	i = 0;
	current = a;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
	current = b;
	i = 0;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

void	reinit_data(t_data *data_lst)
{
	find_small_and_big_nb(data_lst);
	data_lst->size_a = ft_lstsize(data_lst->a);
	data_lst->size_b = ft_lstsize(data_lst->b);
	update_indexes(data_lst->a, data_lst->b);
}

void	print_lst(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		printf ("%d\n", current->content);
		current = current->next;
	}
}
