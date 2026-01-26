/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:22:05 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/26 14:28:32 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*read_line(void)
{
	char	*line;
	char	buffer;
	int		bytes_read;
	int		len;

	len = 0;
	line = malloc(5);
	if (!line)
		return (NULL);
	bytes_read = read(0, &buffer, 1);
	while (bytes_read > 0 && buffer != '\n')
	{
		if (len >= 4)
			return (free(line), (char *)-1);
		line[len++] = buffer;
		bytes_read = read(0, &buffer, 1);
	}
	if (bytes_read < 0 || (bytes_read == 0 && len == 0))
		return (free(line), NULL);
	line[len] = '\0';
	return (line);
}

static int	execute_simple_ops(char *inst, t_stack **a, t_stack **b)
{
	if (inst[0] == 's' && inst[1] == 'a' && inst[2] == '\0')
		sa_no_write(a);
	else if (inst[0] == 's' && inst[1] == 'b' && inst[2] == '\0')
		sb_no_write(b);
	else if (inst[0] == 's' && inst[1] == 's' && inst[2] == '\0')
		ss_no_write(a, b);
	else if (inst[0] == 'p' && inst[1] == 'a' && inst[2] == '\0')
		pa_no_write(a, b);
	else if (inst[0] == 'p' && inst[1] == 'b' && inst[2] == '\0')
		pb_no_write(a, b);
	else if (inst[0] == 'r' && inst[1] == 'a' && inst[2] == '\0')
		ra_no_write(a);
	else if (inst[0] == 'r' && inst[1] == 'b' && inst[2] == '\0')
		rb_no_write(b);
	else if (inst[0] == 'r' && inst[1] == 'r' && inst[2] == '\0')
		rr_no_write(a, b);
	else
		return (0);
	return (1);
}

static int	execute_instruction(char *inst, t_stack **a, t_stack **b)
{
	if (!inst)
		return (0);
	if (execute_simple_ops(inst, a, b))
		return (1);
	if (inst[0] == 'r' && inst[1] == 'r' && inst[2] == 'a'
		&& inst[3] == '\0')
		rra_no_write(a);
	else if (inst[0] == 'r' && inst[1] == 'r' && inst[2] == 'b'
		&& inst[3] == '\0')
		rrb_no_write(b);
	else if (inst[0] == 'r' && inst[1] == 'r' && inst[2] == 'r'
		&& inst[3] == '\0')
		rrr_no_write(a, b);
	else
		return (0);
	return (1);
}

static int	read_and_execute(t_stack **a, t_stack **b)
{
	char	*instruction;

	while (1)
	{
		instruction = read_line();
		if (!instruction)
			break ;
		if (instruction == (char *)-1)
			return (0);
		if (instruction[0] == '\0')
		{
			free(instruction);
			break ;
		}
		if (!execute_instruction(instruction, a, b))
		{
			free(instruction);
			return (0);
		}
		free(instruction);
	}
	return (1);
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
	reverse_stack(&a);
	if (!read_and_execute(&a, &b))
		return (free_stack(&a), free_stack(&b),
			write(2, "Error\n", 6), 1);
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
