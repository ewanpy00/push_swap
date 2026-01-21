#include "push_swap.h"

static void	execute_simultaneous_rotations(t_stack **a, t_stack **b,
		int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	execute_remaining_rotations_a(t_stack **a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
}

static void	execute_remaining_rotations_b(t_stack **b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
}

void	execute_move(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	cost_a;
	int	cost_b;

	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	execute_simultaneous_rotations(a, b, &cost_a, &cost_b);
	execute_remaining_rotations_a(a, &cost_a);
	execute_remaining_rotations_b(b, &cost_b);
}

