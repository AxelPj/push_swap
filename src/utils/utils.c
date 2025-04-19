/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:29:46 by axelpeti          #+#    #+#             */
/*   Updated: 2025/04/19 18:48:53 by axelpeti         ###   ########.fr       */
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

int	*find_big_nb(t_list *stack)
{
	t_list *current;
	int		temp;
	
	current = stack;
	temp = current->content;
	while (current->next)
	{
		if (temp < current->content)
			temp = current->content;
		current = current->next;
	}
	return(temp);
}

int	*find_small_nb (t_list *stack)
{
	t_list *current;
	int		temp;
	
	current = stack;
	temp = current->content;
	while (current->next)
	{
		if (temp > current->content)
			temp = current->content;
		current = current->next;
	}
	return(temp);
}

int	*find_insert_pos (t_list *stack, int x)
{
	t_list *current;
	int index;

	index = 0;
	current = stack;
	while (current->next)
	{
		if (current->content < x && x < current->next->content)
			return (current->next->index);
		current = current->next;
	}
	return (current->next->index);
}

void update_indexes(t_list *a, t_list *b)
{
    int i = 0;
	t_list *current;

	current = a;
    while (current)
    {
        current->index = i;
        current = current->next;
        i++;
    }
	current = b;
	i = 0;
    while (current)
    {
        current->index = i;
        current = current->next;
        i++;
    }
}
int cost_mouv_stack(s_data *data_lst, t_list *node_a, t_list *node_b)
{
	data_lst->index_a = node_a->index;
	data_lst->index_b = node_b->index;
	data_lst->size_a = ft_lstsize(data_lst->a);
	data_lst->size_b = ft_lstsize(data_lst->b);
	if (data_lst->index_a <= data_lst->size_a / 2)
		data_lst->cost_a = (data_lst->size_a - data_lst->index_a);
	else
		data_lst->cost_a = -(data_lst->size_a - data_lst->index_a);

	if (data_lst->index_b <= data_lst->size_b / 2)
		data_lst->cost_b = (data_lst->size_b - data_lst->index_b);
	else
		data_lst->cost_b = -(data_lst->size_b - data_lst->index_b);
	data_lst->total_cost = data_lst->cost_a + data_lst->cost_b;
}

int cost_mouv(s_data *data_lst, int x)
{
	int small;
	int big;
	int cost;

	cost = 0;
	small = find_small_nb(data_lst->b);
	big = find_big_nb(data_lst->b);
	if (x < small)
	{
		
	}
	else if (x > big)
	{
		
	}
	else
	{
		
	}
	
}

void mouv (s_data *data_lst)
{
	pb(&data_lst->a, &data_lst->b);
	pb(&data_lst->a, &data_lst->b);
	update_indexes(data_lst->a, data_lst->b);
	while (data_lst->size_a >= 3)
	{
		
	}
}

// push 2 nb de 'a' dans 'b'
// si x est plus petit que le plus petit nombre de b alors il ira forcement en bas de b
// si x est plus grand que le plus grand nombre de b alors il ira en haut
// si x est entre les deux alors il faudra trouver ou il doit aller
// chercher le couple qui va le mieux avec ce nombre nb b < x < nb b + 1
// enregistrer l'index de b->next->content
// calculer combien de cout pour mettre b->next->content en haut de la pile + 
// combien de cout pour x dans 'b' et rotate 'b'
//
// 