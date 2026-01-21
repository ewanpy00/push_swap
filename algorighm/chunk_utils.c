#include "push_swap.h"

int	stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	in_chunk(t_stack *node, t_chunk *chunk)
{
	if (chunk->chunk_counter == chunk->chunk_amount)
		return (node->index >= (chunk->chunk_counter - 1)
			* chunk->chunk_length);
	return (node->index >= (chunk->chunk_counter - 1) * chunk->chunk_length
		&& node->index < chunk->chunk_counter * chunk->chunk_length);
}

int	chunk_in_stack(t_stack *a, t_chunk *chunk)
{
	while (a)
	{
		if (in_chunk(a, chunk))
			return (1);
		a = a->next;
	}
	return (0);
}

t_stack	*find_closest_in_chunk(t_stack *a, t_chunk *chunk)
{
	int		i;
	int		size;
	t_stack	*tmp;

	i = 0;
	size = stack_size(a);
	tmp = a;
	while (tmp)
	{
		if (in_chunk(tmp, chunk))
		{
			if (i <= size / 2)
				tmp->pos = i;
			else
				tmp->pos = i - size;
			return (tmp);
		}
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}

