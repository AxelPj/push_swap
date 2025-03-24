/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:18:48 by axelpeti          #+#    #+#             */
/*   Updated: 2025/03/24 19:30:42 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

void	ra(t_list **stack_A)
{
	t_list *temp;
	t_list *last;

	if (!(*stack_A) || !(*stack_A)->next)
        return;
	temp = stack_A;
	stack_A = (*stack_A)->next;
	last = stack_A;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = temp;
	temp->next = NULL;
}

void	rb(t_list **stack_B)
{
	t_list *temp;
	t_list *last;

	if (!(*stack_B) || !(*stack_B)->next)
        return;
	temp = stack_B;
	stack_B = (*stack_B)->next;
	last = stack_B;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = temp;
	temp->next = NULL;
}

void	rr(t_list *stack_A, t_list *stack_B)
{
	ra(stack_A);
	rb(stack_B);
}
