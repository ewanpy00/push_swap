/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:22:26 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/21 16:24:28 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_target(t_stack **a, t_stack *target)
{
	while (target->pos > 0)
	{
		ra(a);
		target->pos--;
	}
	while (target->pos < 0)
	{
		rra(a);
		target->pos++;
	}
}

static int	should_rotate_b(t_stack *b, t_chunk *chunk, int moved)
{
	return ((b->index < (chunk->chunk_counter * chunk->chunk_length
				- chunk->chunk_length / 2)) && (moved <= chunk->chunk_length
			/ 2));
}

static void	process_chunk(t_stack **a, t_stack **b, t_chunk *chunk)
{
	t_stack	*target;
	int		moved;

	moved = 0;
	while (chunk_in_stack(*a, chunk))
	{
		target = find_closest_in_chunk(*a, chunk);
		if (!target)
			break ;
		rotate_to_target(a, target);
		pb(a, b);
		moved++;
		if (should_rotate_b(*b, chunk, moved))
			rb(b);
	}
}

void	push_to_b(t_stack **a, t_stack **b, t_chunk *chunk)
{
	while (chunk->chunk_counter <= chunk->chunk_amount)
	{
		process_chunk(a, b, chunk);
		chunk->chunk_counter++;
	}
}
