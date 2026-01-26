/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops_no_write.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:21:55 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/21 16:25:00 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_no_write(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
}

void	sb_no_write(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
}

void	ss_no_write(t_stack **stack_a, t_stack **stack_b)
{
	sa_no_write(stack_a);
	sb_no_write(stack_b);
}

