/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:29:46 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/18 17:35:35 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"


s_data	*init(char **tab_arg, s_data *data_lst)
{
    t_list *stack_b;
    
	data_lst = malloc(sizeof(s_data));
	if (!data_lst)
        return (NULL);
    stack_b = NULL;
	data_lst->a = init_lst(tab_arg, data_lst);
	data_lst->size_lst = ft_lstsize(data_lst->a);
	data_lst->sorted_array = sorted_array(data_lst);
	get_chunk_count(data_lst);
	return (data_lst); 
}

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
}

int	*create_array(s_data *data_lst)
{
	t_list	*current;
	int		i;
	int *array;
	
	array = malloc(data_lst->size_lst * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	current = data_lst->a;
	while (current)
	{
		array[i] = current->content;
		current = current->next;
		i++;
	}
	return (array);
}

int	*sorted_array(s_data *data_lst)
{
	int i;
	int size = (data_lst->size_lst);
	int temp;
	int *array;

	array = create_array(data_lst);
	temp = 0;
	while (size > 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
			}
			i++;
		}
		size--;
	}
	return (array);
}

void	index_to_lst(s_data *data_lst)
{
	int	i;
	t_list *current;

	i = 0;
	while (data_lst->sorted_array[i])
	{
		current = data_lst->a;
		while (current)
		{
			if (data_lst->sorted_array[i] == current->content)
			{
				current->index = i;
				break;
			}
			current = current->next;
		}
		i++;
	}
}

int get_chunk_count(s_data *data_lst)
{
	if (data_lst->size_lst <= 100)
		data_lst->chunk = 5
	else if (data_lst->size_lst > 100 && data_lst->size_lst <= 200)
		data_lst->chunk = 10;
	else if (data_lst->size_lst > 200 && data_lst->size_lst <= 300)
		data_lst->chunk = 15;
	else if (data_lst->size_lst > 300 && data_lst->size_lst <= 400)
		data_lst->chunk = 20;
	else
		data_lst->chunk = 25;
}

void	assign_chunks_to_list(s_data *data_lst)
{
	t_list *current;

	i = 0;
	while (data_lst->sorted_array[i])
	{
		current = data_lst->a;
		while (current)
		{
			if (data_lst->sorted_array[i] == current->content)
			{
				current->index = i;
				break;
			}
			current = current->next;
		}
}