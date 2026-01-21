/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:21:48 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/21 16:25:08 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
