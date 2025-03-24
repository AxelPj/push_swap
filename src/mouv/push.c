/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:26:47 by axel              #+#    #+#             */
/*   Updated: 2025/03/24 19:31:13 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

void	pa(t_list **stack_A, t_list **stack_B)
{
	t_list *temp;

	if (*stack_B == NULL)
		return ;
	temp = *stack_B;
	*stack_B = (*stack_B)->next;
	temp->next = *stack_A;
	*stack_A = temp;
}

void	pb(t_list **stack_A, t_list **stack_B)
{
	t_list *temp;

	if (*stack_A == NULL)
		return ;
	temp = *stack_A;
	*stack_A = (*stack_A)->next;
	temp->next = *stack_B;
	*stack_B = temp;
}
