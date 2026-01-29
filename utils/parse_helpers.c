/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:21:48 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/28 22:50:19 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_one(char *arg, char **args, t_stack **a)
{
	int	value;
	int	error;

	value = ft_atoi(arg, &error);
	if (error || has_duplicates(*a, value))
		return (write(2, "Error\n", 6), free_split(args), free_stack(a), 0);
	if (!init_new_node(a, value))
		return (free_split(args), free_stack(a), 0);
	return (1);
}

static int	parse_args_array(char **args, int arg_count, t_stack **a)
{
	int	i;

	i = 0;
	while (i < arg_count)
	{
		if (!parse_one(args[i], args, a))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_arg_string(char *arg, t_stack **a)
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

int	parse_input(int ac, char **av, t_stack **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!parse_arg_string(av[i], a))
		{
			free_stack(a);
			return (0);
		}
		i++;
	}
	return (1);
}
