/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:25:13 by axel              #+#    #+#             */
/*   Updated: 2025/04/19 18:42:57 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSHSWAP_H
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

typedef struct s_data
{
	t_list *a;
	t_list *b;
	int index_a;
	int index_b;
	int size_a;
	int size_b;
	int cost_a;
	int cost_b;
	int total_cost;
} s_data;

//-----------verif-----------//

char	**arg_to_tab(char **av, int ac);
int		verif_all(char **tab);
int		verif_nb(char **res);
int		verif_limit(char **tab);
int		verif_duplicate(char **tab_arg, int i, int j);

//-----------init_lst-----------//

s_data	*init(char **tab_arg, s_data *data_lst);
t_list	*init_lst(char **tab_arg, s_data *data_lst); 
void	ft_lstadd_frt(t_list **lst, t_list *new);
t_list	*ft_lstnw(int content);
int		ft_lstsize(t_list *lst);

//-----------algo------------//

int		*sorted_array(s_data *data_lst);
int		*create_array(s_data *data_lst);
void	assign_index_to_list(s_data *data_lst);


//-----------mouv-----------//

void	sa(t_list *stack_a);
void	sb(t_list *stack_a);
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