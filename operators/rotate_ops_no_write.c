/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops_no_write.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:21:58 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/21 19:39:54 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_no_write(t_stack **stack_a)
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
}

void	rb_no_write(t_stack **stack_b)
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
}

void	rr_no_write(t_stack **stack_a, t_stack **stack_b)
{
	ra_no_write(stack_a);
	rb_no_write(stack_b);
}

