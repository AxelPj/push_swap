/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:31:01 by axel              #+#    #+#             */
/*   Updated: 2025/04/19 15:41:58 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

void sa(t_list **stack_a)
{
	int	temp;

	temp = (*stack_a)->next->content;
	(*stack_a)->next->content = (*stack_a)->content;
	(*stack_a)->content = temp;
	write (1, "sa", 3);
}

void sb(t_list **stack_b)
{
	int	temp;

	temp = (*stack_b)->next->content;
	(*stack_b)->next->content = (*stack_b)->content;
	(*stack_b)->content = temp;
	write (1, "sb", 3);
}

void ss(t_list *stack_b, t_list *stack_a)
{
	sa(stack_a);
	sb(stack_b);
}
