#include "push_swap.h"

// Get the next minimum number in the stack

static t_list	*ft_get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

// Index the stack

void	ft_index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = ft_get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = ft_get_next_min(stack);
	}
}

