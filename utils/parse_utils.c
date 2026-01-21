#include "push_swap.h"

int	has_duplicates(t_stack *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	validate_value(int value, int error, t_stack **a)
{
	if (error || has_duplicates(*a, value))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

static int	init_new_node(t_stack **a, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	new_node->value = value;
	new_node->index = 0;
	new_node->pos = 0;
	new_node->target_pos = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->size = 0;
	new_node->next = *a;
	*a = new_node;
	return (1);
}

int	parse_arguments(int ac, char **av, t_stack **a)
{
	int	i;
	int	value;
	int	error;

	i = 1;
	while (i < ac)
	{
		value = ft_atoi(av[i], &error);
		if (!validate_value(value, error, a))
			return (0);
		if (!init_new_node(a, value))
			return (0);
		i++;
	}
	return (1);
}

