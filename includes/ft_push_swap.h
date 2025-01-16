/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2025/01/16 17:20:49 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"

// Stack
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

// Util functions
t_list		*ft_lstnew(int value);
t_list		*ft_lstlast(t_list *head);
void		ft_lstadd_front(t_list **stack, t_list *new);
void		ft_lstadd_back(t_list **stack, t_list *new);
void		printList(t_list *head);
int			ft_lstsize(t_list *head);
int			ft_is_int_range(const char *str);
long long	ft_atoll(const char *str);

void		ft_error(char *msg);
void		ft_check_args(int argc, char **argv);
int			ft_is_sorted(t_list **stack);
int			ft_get_distance(t_list **stack, int index);
void		ft_make_top(t_list **stack, int distance);
void		ft_free_stack(t_list **stack);
void		ft_free(char **str);

// Algorithm utils
void		ft_radix_sort(t_list **stack_a, t_list **stack_b);
void		ft_simple_sort(t_list **stack_a, t_list **stack_b);
void		ft_index_stack(t_list **stack);
void		ft_sort_5(t_list **stack_a, t_list **stack_b);

// Instruction functions
int			ft_swap(t_list **stack);
int			ft_push(t_list **stack_to, t_list **stack_from);
int			ft_rotate(t_list **stack);
int			ft_reverse_rotate(t_list **stack);

int			ft_sa(t_list **stack_a);
int			ft_sb(t_list **stack_b);
int			ft_ss(t_list **stack_a, t_list **stack_b);
int			ft_pa(t_list **stack_a, t_list **stack_b);
int			ft_pb(t_list **stack_b, t_list **stack_a);
int			ft_ra(t_list **stack_a);
int			ft_rb(t_list **stack_b);
int			ft_rr(t_list **stack_a, t_list **stack_b);
int			ft_rra(t_list **stack_a);
int			ft_rrb(t_list **stack_b);
int			ft_srrr(t_list **stack_a, t_list **stack_b);

#endif

