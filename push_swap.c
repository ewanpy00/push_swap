/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:21:28 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/21 16:23:01 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_small_stack(t_stack **a, int size)
{
	if (size == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	if (size == 3)
	{
		if ((*a)->value > (*a)->next->value
			&& (*a)->value > (*a)->next->next->value)
			ra(a);
		else if ((*a)->next->value > (*a)->value
			&& (*a)->next->value > (*a)->next->next->value)
			rra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
		free_stack(a);
		return (1);
	}
	if (size <= 1)
	{
		free_stack(a);
		return (1);
	}
	return (0);
}

static void	execute_sorting_algorithm(t_stack **a, t_stack **b, int size)
{
	t_chunk	chunk;

	setup(a, size, &chunk);
	push_to_b(a, b, &chunk);
	push_to_a(a, b);
}

static int	process_stack(t_stack **a, t_stack **b)
{
	int	size;

	reverse_stack(a);
	size = stack_size(*a);
	if (is_sorted(*a))
	{
		free_stack(a);
		return (1);
	}
	if (handle_small_stack(a, size))
		return (1);
	execute_sorting_algorithm(a, b, size);
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
