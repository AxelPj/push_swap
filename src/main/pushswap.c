/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:45:33 by axel              #+#    #+#             */
/*   Updated: 2025/04/17 18:56:45 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

int main (int ac, char **av)
{
	s_data *data_lst;
    char **tab_arg;
    int i;
    i = 0;
    
    data_lst = NULL;
    if  (ac > 1)
    {
        tab_arg = arg_to_tab(av, ac);
        if (verif_all(tab_arg) == 0)
        {
            data_lst = init(tab_arg, data_lst);
            printf("size_lst = %d\n\n", data_lst->size_lst);
            t_list *current;
            current = data_lst->a;
            while (current->next)
            {
                printf ("chaine = %d", data_lst->a->content);
                current = current->next;
            }
        }
    }
    else
        write (2, "error", 5);
}