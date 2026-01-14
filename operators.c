#include "push_swap.h"

void sa(t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    first = *stack_a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
    write(1, "sa\n", 3);
}

void sb(t_stack **stack_b)
{
    t_stack *first;
    t_stack *second;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    first = *stack_b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
    write(1, "sb\n", 3);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first_b;
    t_stack *second_b;
    t_stack *first_a;
    t_stack *second_a;

    if (!stack_b || !*stack_b || !(*stack_b)->next || !stack_a || !*stack_a || !(*stack_a)->next)
        return;
    first_a = *stack_a;
    second_a = first_a->next;
    first_a->next = second_a->next;
    second_a->next = first_a;
    *stack_a = second_a;
    first_b = *stack_b;
    second_b = first_b->next;
    first_b->next = second_b->next;
    second_b->next = first_b;
    *stack_b = second_b;
    write(1, "ss\n", 3);
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;

    if (!stack_b || !*stack_b)
        return;
    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = *stack_a;
    *stack_a = temp;
    write(1, "pa\n", 3);
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;

    if (!stack_a || !*stack_a)
        return;
    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = *stack_b;
    *stack_b = temp;
    write(1, "pb\n", 3);
}

void ra(t_stack **stack_a)
{
    t_stack *first;
    t_stack *last;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    first = *stack_a;
    *stack_a = first->next;
    last = *stack_a;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    write(1, "ra\n", 3);
}

void rb(t_stack **stack_b)
{
    t_stack *first;
    t_stack *last;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    first = *stack_b;
    *stack_b = first->next;
    last = *stack_b;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    write(1, "rb\n", 3);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first_a;
    t_stack *last_a;
    t_stack *first_b;
    t_stack *last_b;

    if (!stack_a || !*stack_a || !(*stack_a)->next || !stack_b || !*stack_b || !(*stack_b)->next)
        return;
    first_a = *stack_a;
    *stack_a = first_a->next;
    last_a = *stack_a;
    while (last_a->next)
        last_a = last_a->next;
    last_a->next = first_a;
    first_a->next = NULL;
    first_b = *stack_b;
    *stack_b = first_b->next;
    last_b = *stack_b;
    while (last_b->next)
        last_b = last_b->next;
    last_b->next = first_b;
    first_b->next = NULL;
    write(1, "rr\n", 3);
}

void rra(t_stack **stack_a)
{
    t_stack *prev;
    t_stack *last;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    prev = NULL;
    last = *stack_a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    write(1, "rra\n", 4);
}

void rrb(t_stack **stack_b)
{
    t_stack *prev;
    t_stack *last;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    prev = NULL;
    last = *stack_b;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    write(1, "rrb\n", 4);
}

void rra_no_write(t_stack **stack_a)
{
    t_stack *prev;
    t_stack *last;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    prev = NULL;
    last = *stack_a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
}

void rrb_no_write(t_stack **stack_b)
{
    t_stack *prev;
    t_stack *last;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    prev = NULL;
    last = *stack_b;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra_no_write(stack_a);
    rrb_no_write(stack_b);
    write(1, "rrr\n", 4);
}