/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2025/01/16 18:11:33 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"

// Defining the stack
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

// List (stack) management functions

t_list		*ft_lstnew(int value);
t_list		*ft_lstlast(t_list *head);
void		ft_lstadd_front(t_list **stack, t_list *new);
void		ft_lstadd_back(t_list **stack, t_list *new);
int			ft_lstsize(t_list *head);
t_list		*ft_get_next_min(t_list **stack);
void		ft_index_stack(t_list **stack);

// Utilitary functions

void		ft_error(char *msg);
void		ft_free(char **str);
int			ft_get_distance(t_list **stack, int index);
void		ft_make_top(t_list **stack, int distance);
void		ft_print_list(t_list *head);
long long	ft_atoll(const char *str);
void		ft_free_stack(t_list **stack);
int			ft_is_int_range(const char *str);

// Validating functions

int			ft_check_duplicates(int num, char **argv, int i);
int			ft_isnum(char *num);
void		ft_check_args(int argc, char **argv);
int			ft_is_sorted(t_list **stack);

// Radix functions

int			ft_get_max_bits(t_list **stack);
void		ft_radix_sort(t_list **stack_a, t_list **stack_b);

// Simple sorting functions

void		ft_sort_3(t_list **stack_a);
void		ft_sort_4(t_list **stack_a, t_list **stack_b);
void		ft_sort_5(t_list **stack_a, t_list **stack_b);
void		ft_simple_sort(t_list **stack_a, t_list **stack_b);

// Push functions

int			ft_push(t_list **stack_to, t_list **stack_from);
int			ft_pa(t_list **stack_a, t_list **stack_b);
int			ft_pb(t_list **stack_b, t_list **stack_a);

// Rotating functions

int			ft_rotate(t_list **stack);
int			ft_ra(t_list **stack_a);
int			ft_rb(t_list **stack_b);
int			ft_rr(t_list **stack_a, t_list **stack_b);

// Reverse rotating functions

int			ft_reverse_rotate(t_list **stack);
int			ft_rra(t_list **stack_a);
int			ft_rrb(t_list **stack_b);
int			ft_rrr(t_list **stack_a, t_list **stack_b);

// Swapping functions

int			ft_swap(t_list **stack);
int			ft_sa(t_list **stack_a);
int			ft_sb(t_list **stack_b);
int			ft_ss(t_list **stack_a, t_list **stack_b);

// Sorting_utilities

int			ft_get_min(t_list **stack, int val);
void		ft_handle_min_case(t_list **stack_a);
void		ft_handle_next_min_case(t_list **stack_a);

// Main support functions

void		ft_init_stack(t_list **stack, int argc, char **argv);
void		ft_sort_stack(t_list **stack_a, t_list **stack_b);

#endif
