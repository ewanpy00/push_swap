/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:22:23 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/21 16:24:26 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_indexes(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*runner;
	int		index;

	current = *stack_a;
	while (current)
	{
		index = 0;
		runner = *stack_a;
		while (runner)
		{
			if (runner->value < current->value)
				index++;
			runner = runner->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	setup(t_stack **a, int total_size, t_chunk *chunk)
{
	if (total_size <= 20)
		chunk->chunk_amount = 2;
	else if (total_size <= 100)
		chunk->chunk_amount = 5;
	else if (total_size <= 500)
		chunk->chunk_amount = 10;
	else
		chunk->chunk_amount = 20;
	chunk->chunk_length = total_size / chunk->chunk_amount;
	chunk->chunk_counter = 1;
	set_indexes(a);
}
