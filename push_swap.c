/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:21:28 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/26 11:57:47 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void	sort_three(t_stack **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		ra(a);
	else if ((*a)->next->value > (*a)->value
		&& (*a)->next->value > (*a)->next->next->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static void	push_min_to_b(t_stack **a, t_stack **b, int target_index)
{
	int		pos;
	int		size;
	t_stack	*current;

	current = *a;
	pos = 0;
	size = stack_size(*a);
	while (current && current->index != target_index)
	{
		pos++;
		current = current->next;
	}
	while ((*a)->index != target_index)
	{
		if (pos <= size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
}

static void	sort_five(t_stack **a, t_stack **b)
{
	set_indexes(a);
	push_min_to_b(a, b, 0);
	push_min_to_b(a, b, 1);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

static int	process_stack(t_stack **a, t_stack **b)
{
	int		size;
	t_chunk	chunk;

	reverse_stack(a);
	size = stack_size(*a);
	if (is_sorted(*a) || size <= 1)
		return (free_stack(a), 1);
	if (size == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	if (size == 3 || size == 5)
	{
		if (size == 3)
			sort_three(a);
		else
			sort_five(a, b);
		return (free_stack(a), 1);
	}
	setup(a, size, &chunk);
	push_to_b(a, b, &chunk);
	push_to_a(a, b);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_input(ac, av, &a))
		return (1);
	process_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

