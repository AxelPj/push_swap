/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:41:59 by axel              #+#    #+#             */
/*   Updated: 2025/04/26 20:49:28 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header/pushswap.h"

t_data	*init(char **tab_arg, t_data *data_lst)
{
	data_lst = malloc(sizeof(t_data));
	if (!data_lst)
		return (NULL);
	data_lst->a = NULL;
	data_lst->b = NULL;
	if (data_lst->a)
	data_lst->size_a = 0;
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
		ft_lstadd_bck(&data_lst->a, new_node);
		i++;
	}
	return (data_lst->a);
}

void	ft_lstadd_bck(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		last = lstlast(*lst);
		last->next = new;
	}
}

t_list	*lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
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
	t_list *current;

	current = lst;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
