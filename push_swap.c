#include "push_swap.h"
#include <limits.h>

int	ft_atoi(const char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	*error = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
	{
		*error = 1;
		return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && result < INT_MIN))
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	if (str[i] != '\0')
	{
		*error = 1;
		return (0);
	}
	return ((int)(result * sign));
}

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

int	parse_arguments(int ac, char **av, t_stack **a)
{
	int		i;
	int		value;
	int		error;
	t_stack	*new_node;

	i = 1;
	while (i < ac)
	{
		value = ft_atoi(av[i], &error);
		if (error)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (has_duplicates(*a, value))
		{
			write(2, "Error\n", 6);
			return (0);
		}
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
		i++;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	is_sorted(t_stack *a)
{
	if (!a || !a->next)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	reverse_stack(t_stack **a)
{
	t_stack	*prev;
	t_stack	*current;
	t_stack	*next;

	prev = NULL;
	current = *a;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*a = prev;
}


int	count_words(char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if ((*str == ' ' || *str == '\t') && in_word)
			in_word = 0;
		str++;
	}
	return (count);
}

char	**split_arguments(char *str, int *count)
{
	char	**result;
	int		i;
	int		j;
	int		start;
	int		k;

	*count = count_words(str);
	if (*count == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (*count + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j < *count)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!str[i])
			break;
		start = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
		result[j] = malloc(i - start + 1);
		if (!result[j])
		{
			while (j-- > 0)
				free(result[j]);
			free(result);
			return (NULL);
		}
		k = 0;
		while (start < i)
			result[j][k++] = str[start++];
		result[j][k] = '\0';
		j++;
	}
	result[j] = NULL;
	return (result);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_chunk	chunk;
	int		size;
	char	**args;
	int		arg_count;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		args = split_arguments(av[1], &arg_count);
		if (!args || arg_count == 0)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (!parse_arguments(arg_count + 1, args, &a))
		{
			free_split(args);
			free_stack(&a);
			return (1);
		}
		free_split(args);
	}
	else
	{
		if (!parse_arguments(ac, av, &a))
		{
			free_stack(&a);
			return (1);
		}
	}
	reverse_stack(&a);
	size = stack_size(a);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (size == 2 && a->value > a->next->value)
		sa(&a);
	if (size == 3)
	{
		if (a->value > a->next->value && a->value > a->next->next->value)
			ra(&a);
		else if (a->next->value > a->value && a->next->value > a->next->next->value)
			rra(&a);
		if (a->value > a->next->value)
			sa(&a);
		free_stack(&a);
		return (0);
	}
	if (size <= 1)
	{
		free_stack(&a);
		return (0);
	}
	setup(&a, size, &chunk);
	push_to_b(&a, &b, &chunk);
	push_to_a(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
