/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:04:20 by ipykhtin          #+#    #+#             */
/*   Updated: 2026/01/21 16:50:10 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_result_array(char **result, int j)
{
	while (j-- > 0)
		free(result[j]);
	free(result);
}

static int	alloc_word(char **result, int *counter, int start, char *str)
{
	int	k;
	int	j;
	int	end;

	j = counter[1];
	end = counter[0];
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
	int		start;
	int		counter[2];

	counter[0] = 0;
	counter[1] = 0;
	*count = count_words(str);
	if (*count == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (*count + 1));
	if (!result)
		return (NULL);
	while (str[counter[0]] && counter[1] < *count)
	{
		if (!extract_word(str, &counter[0], &start))
			break ;
		if (!alloc_word(result, counter, start, str))
			return (NULL);
		counter[1]++;
	}
	result[counter[1]] = NULL;
	return (result);
}
