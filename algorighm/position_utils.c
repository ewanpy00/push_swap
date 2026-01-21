#include "push_swap.h"
#include <limits.h>

void	set_positions(t_stack *stack)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(stack);
	while (stack)
	{
		if (i <= size / 2)
			stack->pos = i;
		else
			stack->pos = i - size;
		stack = stack->next;
		i++;
	}
}

int	get_min_index_pos(t_stack *a)
{
	int	min_index;
	int	min_pos;
	int	pos;

	min_index = INT_MAX;
	min_pos = 0;
	pos = 0;
	while (a)
	{
		if (a->index < min_index)
		{
			min_index = a->index;
			min_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (min_pos);
}

static int	find_best_position(t_stack *a, int b_index, int *best_pos)
{
	t_stack	*current_a;
	int		target_pos;
	int		found;
	int		best_index;

	current_a = a;
	target_pos = 0;
	found = 0;
	best_index = INT_MAX;
	while (current_a)
	{
		if (current_a->index > b_index && current_a->index < best_index)
		{
			best_index = current_a->index;
			*best_pos = target_pos;
			found = 1;
		}
		target_pos++;
		current_a = current_a->next;
	}
	return (found);
}

static void	set_target_for_node(t_stack *a, t_stack *b_node, int size_a)
{
	int	best_pos;
	int	min_pos;

	if (find_best_position(a, b_node->index, &best_pos))
	{
		if (best_pos <= size_a / 2)
			b_node->target_pos = best_pos;
		else
			b_node->target_pos = best_pos - size_a;
	}
	else
	{
		min_pos = get_min_index_pos(a);
		if (min_pos <= size_a / 2)
			b_node->target_pos = min_pos;
		else
			b_node->target_pos = min_pos - size_a;
	}
}

void	set_target_pos(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	int		size_a;

	current_b = b;
	size_a = stack_size(a);
	while (current_b)
	{
		set_target_for_node(a, current_b, size_a);
		current_b = current_b->next;
	}
}

