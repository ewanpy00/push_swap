#include "push_swap.h"
#include <limits.h>

static void	init_atoi_state(long *result, int *sign, int *i, int *error)
{
	*result = 0;
	*sign = 1;
	*i = 0;
	*error = 0;
}

static void	handle_sign(const char *str, int *i, int *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

static int	validate_first_digit(const char *str, int i, int *error)
{
	if (str[i] == '\0')
	{
		*error = 1;
		return (0);
	}
	return (1);
}

static int	process_digits(const char *str, long *result, int sign, int *i)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result = *result * 10 + (str[*i] - '0');
		if ((sign == 1 && *result > INT_MAX) || (sign == -1
				&& *result < INT_MIN))
			return (0);
		(*i)++;
	}
	return (1);
}

int	ft_atoi(const char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	init_atoi_state(&result, &sign, &i, error);
	handle_sign(str, &i, &sign);
	if (!validate_first_digit(str, i, error))
		return (0);
	if (!process_digits(str, &result, sign, &i))
	{
		*error = 1;
		return (0);
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

static void	free_result_array(char **result, int j)
{
	while (j-- > 0)
		free(result[j]);
	free(result);
}

static int	alloc_word(char **result, int j, int start, int end, char *str)
{
	int	k;

	result[j] = malloc(end - start + 1);
	if (!result[j])
	{
		free_result_array(result, j);
		return (0);
	}
	k = 0;
	while (start < end)
		result[j][k++] = str[start++];
	result[j][k] = '\0';
	return (1);
}

static int	skip_whitespace(char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	return (str[*i] != '\0');
}

static int	extract_word(char *str, int *i, int *start)
{
	if (!skip_whitespace(str, i))
		return (0);
	*start = *i;
	while (str[*i] && str[*i] != ' ' && str[*i] != '\t')
		(*i)++;
	return (1);
}

char	**split_arguments(char *str, int *count)
{
	char	**result;
	int		i;
	int		j;
	int		start;

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
		if (!extract_word(str, &i, &start))
			break ;
		if (!alloc_word(result, j, start, i, str))
			return (NULL);
		j++;
	}
	result[j] = NULL;
	return (result);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	parse_single_arg(char *arg, t_stack **a)
{
	char	**args;
	int		arg_count;

	args = split_arguments(arg, &arg_count);
	if (!args || arg_count == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!parse_arguments(arg_count + 1, args, a))
	{
		free_split(args);
		free_stack(a);
		return (0);
	}
	free_split(args);
	return (1);
}

static int	parse_multiple_args(int ac, char **av, t_stack **a)
{
	if (!parse_arguments(ac, av, a))
	{
		free_stack(a);
		return (0);
	}
	return (1);
}

static int	handle_small_stack(t_stack **a, int size)
{
	if (size == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	if (size == 3)
	{
		if ((*a)->value > (*a)->next->value
			&& (*a)->value > (*a)->next->next->value)
			ra(a);
		else if ((*a)->next->value > (*a)->value
			&& (*a)->next->value > (*a)->next->next->value)
			rra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
		free_stack(a);
		return (1);
	}
	if (size <= 1)
	{
		free_stack(a);
		return (1);
	}
	return (0);
}

static void	execute_sorting_algorithm(t_stack **a, t_stack **b, int size)
{
	t_chunk	chunk;

	setup(a, size, &chunk);
	push_to_b(a, b, &chunk);
	push_to_a(a, b);
}

static int	parse_input(int ac, char **av, t_stack **a)
{
	if (ac == 2)
	{
		if (!parse_single_arg(av[1], a))
			return (0);
	}
	else
	{
		if (!parse_multiple_args(ac, av, a))
			return (0);
	}
	return (1);
}

static int	process_stack(t_stack **a, t_stack **b)
{
	int	size;

	reverse_stack(a);
	size = stack_size(*a);
	if (is_sorted(*a))
	{
		free_stack(a);
		return (1);
	}
	if (handle_small_stack(a, size))
		return (1);
	execute_sorting_algorithm(a, b, size);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_input(ac, av, &a))
		return (1);
	process_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
