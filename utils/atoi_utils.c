/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:21:51 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/21 16:25:04 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
