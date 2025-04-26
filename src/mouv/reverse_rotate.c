/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:05:07 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/26 17:47:47 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

void	rra(t_list **stack_a, int bool)
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
	if (bool == 0)
		write (1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int bool)
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
	if (bool == 0)
		write (1, "rrb\n", 4);
}

void	rrr(t_list **stack_b, t_list **stack_a)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	write (1, "rrr\n", 4);
}
