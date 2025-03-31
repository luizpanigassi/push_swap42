/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_simple_sorting_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:29:02 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/16 18:12:09 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	ft_handle_min_case(t_list **stack_a)
{
	ft_ra(stack_a);
	ft_sa(stack_a);
	ft_rra(stack_a);
}

void	ft_handle_next_min_case(t_list **stack_a)
{
	if ((*stack_a)->next->index == ft_get_min(stack_a, -1))
		ft_sa(stack_a);
	else
		ft_rra(stack_a);
}
