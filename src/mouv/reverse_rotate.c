/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:05:07 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/21 18:26:26 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*temp;

	last = *stack_a;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
	write (1, "rra", 3);
}

void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*temp;

	last = *stack_b;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *stack_b;
	*stack_b = temp;
	write (1, "rrb", 3);
}

void	rrr(t_list **stack_b, t_list **stack_a)
{
	rra(stack_a);
	rrb(stack_b);
}
