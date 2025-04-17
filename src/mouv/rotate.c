/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:18:48 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/15 15:51:56 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

void	ra(t_list **stack_a)
{
	t_list *temp;
	t_list *last;

	if (!(*stack_a) || !(*stack_a)->next)
        return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	write (1, "ra", 3);
}

void	rb(t_list **stack_b)
{
	t_list *temp;
	t_list *last;

	if (!(*stack_b) || !(*stack_b)->next)
        return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	write (1, "rb", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
