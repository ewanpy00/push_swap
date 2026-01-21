#include "push_swap.h"

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

