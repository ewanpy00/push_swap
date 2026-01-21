/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:22:17 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/21 16:24:22 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	set_costs(t_stack *b)
{
	int		size_b;
	int		pos_b;
	t_stack	*current;

	size_b = stack_size(b);
	pos_b = 0;
	current = b;
	while (current)
	{
		if (pos_b <= size_b / 2)
			current->cost_b = pos_b;
		else
			current->cost_b = pos_b - size_b;
		current->cost_a = current->target_pos;
		current = current->next;
		pos_b++;
	}
}

int	calculate_total_cost(int cost_a, int cost_b)
{
	int	total;

	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (cost_a > 0 && cost_b > 0)
			total = (cost_a > cost_b) ? cost_a : cost_b;
		else
			total = (abs(cost_a) > abs(cost_b)) ? abs(cost_a) : abs(cost_b);
	}
	else
	{
		total = abs(cost_a) + abs(cost_b);
	}
	return (total);
}

t_stack	*get_cheapest(t_stack *b)
{
	t_stack	*cheapest;
	t_stack	*current;
	int		cheapest_cost;
	int		current_cost;

	if (!b)
		return (NULL);
	cheapest = b;
	current = b;
	cheapest_cost = calculate_total_cost(b->cost_a, b->cost_b);
	current = current->next;
	while (current)
	{
		current_cost = calculate_total_cost(current->cost_a, current->cost_b);
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
