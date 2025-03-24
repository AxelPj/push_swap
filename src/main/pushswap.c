/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:45:33 by axel              #+#    #+#             */
/*   Updated: 2025/03/24 19:32:44 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

int main (int argc, char **argv)
{
    t_list *stack_A;
    //t_stack *stack_B;
    
    stack_A = NULL;
    //stack_B = NULL;

    if (argc > 1)
    {
        if (verif_all(argc, argv) == 0)
        {
            stack_A = init_lst(argc, argv, stack_A);
            while (stack_A)
            {
                printf("%i\n", stack_A->content);
                stack_A = stack_A->next;
            }
            ra(&stack_A);
            while (stack_A)
            {
                printf("%i\n", stack_A->content);
                stack_A = stack_A->next;
            }
        }
        else
            write (2, "error", 5);
    }
}