/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:41:59 by axel              #+#    #+#             */
/*   Updated: 2025/03/21 19:32:14 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

t_list *init_lst(int argc, char **argv, t_list *stack_a)
{
    int i;
    int nb;
    t_list *new_node;
    
    i = 1;
    stack_a = NULL;
    while (i < argc)
    {
        nb = atoi(argv[i]);
        new_node = ft_lstnw(nb);
        if (!new_node)
        {
            printf("Erreur d'allocation mémoire\n");
            return (NULL);
        }
        ft_lstadd_frt(&stack_a, new_node);
        i++;
    }
    return(stack_a);
}

void	ft_lstadd_frt(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnw(int content)
{
	t_list	*newelem;

	newelem = (t_list *) malloc(sizeof(t_list));
	if (!newelem)
		return (NULL);
	newelem->content = content;
	newelem->next = NULL;
	return (newelem);
}
int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}