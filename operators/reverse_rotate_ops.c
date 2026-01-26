/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:22:00 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/26 14:34:55 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
