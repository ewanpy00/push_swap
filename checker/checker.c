#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>

int is_sorted(t_stack *a)
{
    while (a && a->next)
    {
        if (a->value > a->next->value)
            return 0;
        a = a->next;
    }
    return 1;
}

void checker(t_stack **a, t_stack **b)
{
    if (is_sorted(*a) && *b == NULL)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}
