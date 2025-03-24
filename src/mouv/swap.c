/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:31:01 by axel              #+#    #+#             */
/*   Updated: 2025/03/24 19:29:44 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

void sa(t_list *stack_A)
{
	int	temp;

	temp = stack_A->next->content;
	stack_A->next->content = stack_A->content;
	stack_A->content = temp;
}

void sb(t_list *stack_B)
{
	int	temp;

	temp = stack_B->next->content;
	stack_B->next->content = stack_B->content;
	stack_B->content = temp;
}

void ss(t_list *stack_B, t_list *stack_A)
{
	sa(stack_A);
	sb(stack_B);
}
