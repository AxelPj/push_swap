/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:25:13 by axel              #+#    #+#             */
/*   Updated: 2025/03/24 19:31:08 by axelpeti         ###   ########.fr       */
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
	struct s_list	*next;
}	t_list;

//-----------verif-----------//

int     verif_all(int argc, char **argv);
int     verif_nb(int argc, char **argv);
int     verif_limit(int argc, char **argv);
t_list  *init_lst(int argc, char **argv, t_list *stack_a);
void	ft_lstadd_frt(t_list **lst, t_list *new);
t_list	*ft_lstnw(int content);

//-----------mouv-----------//

void	sa(t_list *stack_A);
void	sb(t_list *stack_A);
void	ss(t_list *stack_B, t_list *stack_A);
void	ra(t_list **stack_A);
void	rb(t_list **stack_A);
void	rr(t_list **stack_A);
void	pa(t_list **stack_A, t_list **stack_B);
void	pb(t_list **stack_A, t_list **stack_B);

#endif