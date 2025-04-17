/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:29:46 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/17 18:56:27 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"


s_data	*init(char **tab_arg, s_data *data_lst)
{
	t_list *stack_a;
    t_list *stack_b;
    
	data_lst = malloc(sizeof(s_data));
	if (!data_lst)
        return (NULL);
    stack_b = NULL;
	stack_a = NULL;
	stack_a = init_lst(tab_arg, stack_a);
	data_lst->a = stack_a;
	data_lst->size_lst = ft_lstsize(stack_a);
	data_lst->sorted_array = create_array(data_lst);
	sorted_array(data_lst);
	return (data_lst);
}
/* 
int check_sort_lst(t_list **stack_a)
{
    t_list *current;
    int temp;

    temp = 0;
    current = *stack_a;
    while (current->next)
    {
        if (current->content < current->next->content)
            return (1);
        current = current->next;
    }
    return (0);
} */

int	*create_array(s_data *data_lst)
{
	t_list	*current;
	int		i;
	
	data_lst->sorted_array = malloc(data_lst->size_lst * sizeof(int));
	i = 0;
	current = data_lst->a;
	while (current)
	{
		data_lst->sorted_array[i] = current->content;
		current = current->next;
		i++;
	}
	return (data_lst->sorted_array);
}

void	sorted_array(s_data *data_lst)
{
	int i;
	int size = (data_lst->size_lst);
	int temp;
	
	i = 0;
	temp = 0;
	while (size > 0)
	{
		while (i < size)
		{
			if (data_lst->sorted_array[i] < data_lst->sorted_array[i + 1])
			{
				temp = data_lst->sorted_array[i];
				data_lst->sorted_array[i] = data_lst->sorted_array[i + 1];
				data_lst->sorted_array[i + 1] = temp;
			}
			i++;
		}
		size--;
	}
}