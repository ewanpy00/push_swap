/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:21:58 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/21 19:39:54 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*last_a;
	t_stack	*first_b;
	t_stack	*last_b;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !stack_b || !*stack_b
		|| !(*stack_b)->next)
		return ;
	first_a = *stack_a;
	*stack_a = first_a->next;
	last_a = *stack_a;
	while (last_a->next)
		last_a = last_a->next;
	last_a->next = first_a;
	first_a->next = NULL;
	first_b = *stack_b;
	*stack_b = first_b->next;
	last_b = *stack_b;
	while (last_b->next)
		last_b = last_b->next;
	last_b->next = first_b;
	first_b->next = NULL;
	write(1, "rr\n", 3);
}
