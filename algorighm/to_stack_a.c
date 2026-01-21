#include "push_swap.h"

void	final_rotate(t_stack **a)
{
	int	min_pos;
	int	size;

	set_positions(*a);
	min_pos = get_min_index_pos(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (*b)
	{
		set_positions(*a);
		set_positions(*b);
		set_target_pos(*a, *b);
		set_costs(*b);
		cheapest = get_cheapest(*b);
		if (!cheapest)
			break ;
		execute_move(a, b, cheapest);
		pa(a, b);
	}
	final_rotate(a);
}
