/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:25:13 by axel              #+#    #+#             */
/*   Updated: 2025/04/22 15:38:51 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct t_data
{
	t_list	*a;
	t_list	*b;
	int		cost_a;
	int		cost_b;
	int		temp_cost_a;
	int		temp_cost_b;
	int		size_a;
	int		size_b;
	int		temp_cost_total;
	int		total_cost;
	int		small_b;
	int		biggest_b;
	int		index_big_b;
	int		index_small_b;
	int		index_b;
	int		index_a;
}	t_data;

//-----------verif-----------//
char	**arg_to_tab(char **av, int ac);
int		verif_all(char **tab);
int		verif_nb(char **res);
int		verif_limit(char **tab);
int		verif_duplicate(char **tab_arg, int i, int j);

//-----------lst-----------//
t_data	*init(char **tab_arg, t_data *data_lst);
t_list	*init_lst(char **tab_arg, t_data *data_lst);
void	ft_lstadd_frt(t_list **lst, t_list *new);
t_list	*ft_lstnw(int content);
int		ft_lstsize(t_list *lst);
void	mouv_all(t_data *data_lst);
void	mouv_a(t_data *data_lst);
void	mouv_b(t_data *data_lst);

//-----------algo------------//
void	check_place(t_data *data_lst);
void	cost_mouv_stack(t_data *data_lst, int index_a, int index_b);
int		find_insert_pos(t_list *stack, int x);
void	find_small_and_big_nb(t_data *data_lst);

//-----------utils-----------//
void	update_indexes(t_list *a, t_list *b);
void	reinit_data(t_data *data_lst);
void	print_lst(t_list *stack);
int		check_sort_lst(t_list **stack_a);

//-----------mouv-----------//
void	sa(t_list **stack_a);
void	sb(t_list **stack_a);
void	ss(t_list *stack_b, t_list *stack_a);
void	ra(t_list **stack_a);
void	rb(t_list **stack_a);
void	rr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	rrb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrr(t_list **stack_b, t_list **stack_a);

#endif