#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

void set_positions(t_stack *stack)
{
    int i = 0;
    int size = stack_size(stack);

    while (stack)
    {
        if (i <= size / 2)
            stack->pos = i;
        else
            stack->pos = i - size;
        stack = stack->next;
        i++;
    }
}

int get_min_index_pos(t_stack *a)
{
    int min_index = INT_MAX;
    int min_pos = 0;
    int pos = 0;

    while (a)
    {
        if (a->index < min_index)
        {
            min_index = a->index;
            min_pos = pos;
        }
        pos++;
        a = a->next;
    }
    return min_pos;
}

static int find_best_position(t_stack *a, int b_index, int *best_pos)
{
    t_stack *current_a = a;
    int target_pos = 0;
    int found = 0;
    int best_index = INT_MAX;

    while (current_a)
    {
        if (current_a->index > b_index && current_a->index < best_index)
        {
            best_index = current_a->index;
            *best_pos = target_pos;
            found = 1;
        }
        target_pos++;
        current_a = current_a->next;
    }
    return (found);
}

static void set_target_for_node(t_stack *a, t_stack *b_node, int size_a)
{
    int best_pos;
    int min_pos;

    if (find_best_position(a, b_node->index, &best_pos))
    {
        if (best_pos <= size_a / 2)
            b_node->target_pos = best_pos;
        else
            b_node->target_pos = best_pos - size_a;
    }
    else
    {
        min_pos = get_min_index_pos(a);
        if (min_pos <= size_a / 2)
            b_node->target_pos = min_pos;
        else
            b_node->target_pos = min_pos - size_a;
    }
}

void set_target_pos(t_stack *a, t_stack *b)
{
    t_stack *current_b = b;
    int size_a = stack_size(a);

    while (current_b)
    {
        set_target_for_node(a, current_b, size_a);
        current_b = current_b->next;
    }
}

void set_costs(t_stack *b)
{
    int size_b = stack_size(b);
    int pos_b = 0;
    t_stack *current = b;

    while (current)
    {
        if (pos_b <= size_b / 2)
            current->cost_b = pos_b;
        else
            current->cost_b = pos_b - size_b;
        
        current->cost_a = current->target_pos;
        current = current->next;
        pos_b++;
    }
}

int calculate_total_cost(int cost_a, int cost_b)
{
    int total;

    if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
    {
        if (cost_a > 0 && cost_b > 0)
            total = (cost_a > cost_b) ? cost_a : cost_b;
        else
            total = (abs(cost_a) > abs(cost_b)) ? abs(cost_a) : abs(cost_b);
    }
    else
    {
        total = abs(cost_a) + abs(cost_b);
    }
    return total;
}

t_stack *get_cheapest(t_stack *b)
{
    t_stack *cheapest = b;
    t_stack *current = b;
    int cheapest_cost;
    int current_cost;

    if (!b)
        return NULL;

    cheapest_cost = calculate_total_cost(b->cost_a, b->cost_b);
    current = current->next;

    while (current)
    {
        current_cost = calculate_total_cost(current->cost_a, current->cost_b);
        if (current_cost < cheapest_cost)
        {
            cheapest_cost = current_cost;
            cheapest = current;
        }
        current = current->next;
    }
    return cheapest;
}

static void execute_simultaneous_rotations(t_stack **a, t_stack **b,
                                          int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        rr(a, b);
        (*cost_a)--;
        (*cost_b)--;
    }
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(a, b);
        (*cost_a)++;
        (*cost_b)++;
    }
}

static void execute_remaining_rotations_a(t_stack **a, int *cost_a)
{
    while (*cost_a > 0)
    {
        ra(a);
        (*cost_a)--;
    }
    while (*cost_a < 0)
    {
        rra(a);
        (*cost_a)++;
    }
}

static void execute_remaining_rotations_b(t_stack **b, int *cost_b)
{
    while (*cost_b > 0)
    {
        rb(b);
        (*cost_b)--;
    }
    while (*cost_b < 0)
    {
        rrb(b);
        (*cost_b)++;
    }
}

void execute_move(t_stack **a, t_stack **b, t_stack *cheapest)
{
    int cost_a = cheapest->cost_a;
    int cost_b = cheapest->cost_b;

    execute_simultaneous_rotations(a, b, &cost_a, &cost_b);
    execute_remaining_rotations_a(a, &cost_a);
    execute_remaining_rotations_b(b, &cost_b);
}

void final_rotate(t_stack **a)
{
    set_positions(*a);
    int min_pos = get_min_index_pos(*a);
    int size = stack_size(*a);

    if (min_pos <= size / 2)
    {
        while (min_pos > 0)
        {
            ra(a);
            min_pos--;
        }
    }
    else
    {
        while (min_pos < size)
        {
            rra(a);
            min_pos++;
        }
    }
}

void push_to_a(t_stack **a, t_stack **b)
{
    t_stack *cheapest;

    while (*b)
    {
        set_positions(*a);
        set_positions(*b);
        set_target_pos(*a, *b);
        set_costs(*b);
        cheapest = get_cheapest(*b);
        if (!cheapest)
            break;
        execute_move(a, b, cheapest);
        pa(a, b);
    }
    final_rotate(a);
}
