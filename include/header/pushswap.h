/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:25:13 by axel              #+#    #+#             */
/*   Updated: 2025/04/26 19:36:24 by axelpeti         ###   ########.fr       */
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
	int		small_nb;
	int		biggest_nb;
	int		index_big_nb;
	int		index_small_nb;
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
t_list	*ft_lstnw(int content);
int		ft_lstsize(t_list *lst);
void	mouv_a_to_b(t_data *data_lst);
void	mouv_a(t_data *data_lst);
void	mouv_b(t_data *data_lst);
t_list	*lstlast(t_list *lst);
void	ft_lstadd_bck(t_list **lst, t_list *new);

//-----------a_to_b------------//
void	check_place_a_to_b(t_data *data_lst);
void	cost_mouv_stack(t_data *data_lst, int index_a, int index_b);
int		find_insert_pos_a_to_b(t_list *stack, int x);
int		find_insert_pos_b_to_a(t_list *stack, int x);
void	find_small_and_big_nb(t_data *data_lst, t_list *stack);

//-----------b_to_a------------//
int		find_insert_pos_b_to_a(t_list *stack, int x);
void	mouv_b_to_a(t_data *data_lst);
void	check_place_b_to_a(t_data *data_lst);

//-----------utils-----------//
void	update_indexes(t_list *stack_push, t_list *stack_receive);
void	reinit_data(t_data *data_lst, t_list *stack_receive);
void	print_lst(t_data *data_lst);
int		check_sort_lst(t_list **stack_a);
int		verif_sort(t_list *stack);
void	sort_three(t_data *data_lst);
void	sort_a(t_data *data_lst);

//-----------mouv-----------//
void	sb(t_list **stack_b, int bool);
void	sa(t_list **stack_a, int bool);
void	ss(t_list *stack_b, t_list *stack_a);
void	ra(t_list **stack_a,int bool);
void	rb(t_list **stack_a,int bool);
void	rr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	rrb(t_list **stack_b, int bool);
void	rra(t_list **stack_a, int bool);
void	rrr(t_list **stack_b, t_list **stack_a);

#endif