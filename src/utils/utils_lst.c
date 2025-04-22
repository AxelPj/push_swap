/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:41:59 by axel              #+#    #+#             */
/*   Updated: 2025/04/22 18:02:22 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

t_data	*init(char **tab_arg, t_data *data_lst)
{
	t_list	*stack_b;

	data_lst = malloc(sizeof(t_data));
	if (!data_lst)
		return (NULL);
	stack_b = NULL;
	data_lst->a = init_lst(tab_arg, data_lst);
	data_lst->size_a = ft_lstsize(data_lst->a);
	data_lst->cost_a = 0;
	data_lst->cost_b = 0;
	data_lst->temp_cost_a = 0;
	data_lst->temp_cost_b = 0;
	data_lst->size_b = 0;
	data_lst->index_b = 0;
	data_lst->index_a = 0;
	data_lst->total_cost = 0;
	data_lst->temp_cost_total = 0;
	return (data_lst);
}

t_list	*init_lst(char **tab_arg, t_data *data_lst)
{
	int		i;
	t_list	*new_node;

	i = 0;
	while (tab_arg[i])
	{
		new_node = ft_lstnw(atoi(tab_arg[i]));
		if (!new_node)
		{
			printf("Error\n");
			return (NULL);
		}
		ft_lstadd_frt(&data_lst->a, new_node);
		i++;
	}
	return (data_lst->a);
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
