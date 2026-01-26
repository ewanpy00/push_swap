/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:22:00 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/21 16:24:50 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_no_write(t_stack **stack_a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	prev = NULL;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	rrb_no_write(t_stack **stack_b)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	prev = NULL;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

void	rra(t_stack **stack_a)
{
	rra_no_write(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	rrb_no_write(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra_no_write(stack_a);
	rrb_no_write(stack_b);
	write(1, "rrr\n", 4);
}

void	rrr_no_write(t_stack **stack_a, t_stack **stack_b)
{
	rra_no_write(stack_a);
	rrb_no_write(stack_b);
}
