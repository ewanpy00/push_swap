/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:21:48 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/23 22:24:10 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_args_array(char **args, int arg_count, t_stack **a)
{
	int	i;
	int	value;
	int	error;

	i = 0;
	while (i < arg_count)
	{
		value = ft_atoi(args[i], &error);
		if (error || has_duplicates(*a, value))
		{
			write(2, "Error\n", 6);
			free_split(args);
			free_stack(a);
			return (0);
		}
		if (!init_new_node(a, value))
		{
			free_split(args);
			free_stack(a);
			return (0);
		}
		i++;
	}
	return (1);
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
	if (!parse_args_array(args, arg_count, a))
		return (0);
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

int	parse_input(int ac, char **av, t_stack **a)
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
