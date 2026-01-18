#include "push_swap.h"

int stack_size(t_stack *a)
{
    int i = 0;
    while (a)
    {
        i++;
        a = a->next;
    }
    return i;
}

int in_chunk(t_stack *node, t_chunk *chunk)
{
    if (chunk->chunk_counter == chunk->chunk_amount)
        return (node->index >= (chunk->chunk_counter - 1)
                * chunk->chunk_length);
    return (node->index >= (chunk->chunk_counter - 1)
            * chunk->chunk_length
            && node->index < chunk->chunk_counter
            * chunk->chunk_length);
}

int chunk_in_stack(t_stack *a, t_chunk *chunk)
{
    while (a)
    {
        if (in_chunk(a, chunk))
            return 1;
        a = a->next;
    }
    return 0;
}

void set_indexes(t_stack **stack_a)
{
    t_stack *current;
    t_stack *runner;
    int index;

    current = *stack_a;
    while (current)
    {
        index = 0;
        runner = *stack_a;
        while (runner)
        {
            if (runner->value < current->value)
                index++;
            runner = runner->next;
        }
        current->index = index;
        current = current->next;
    }
}

t_stack *find_closest_in_chunk(t_stack *a, t_chunk *chunk)
{
    int i = 0;
    int size = stack_size(a);
    t_stack *tmp = a;

    while (tmp)
    {
        if (in_chunk(tmp, chunk))
        {
            if (i <= size / 2)
                tmp->pos = i;
            else
                tmp->pos = i - size;
            return tmp;
        }
        tmp = tmp->next;
        i++;
    }
    return NULL;
}

void setup(t_stack **a, int total_size, t_chunk *chunk)
{
    if (total_size <= 20)
        chunk->chunk_amount = 2;
    else if (total_size <= 100)
        chunk->chunk_amount = 5;
    else if (total_size <= 500)
        chunk->chunk_amount = 10;
    else
        chunk->chunk_amount = 20;

    chunk->chunk_length = total_size / chunk->chunk_amount;
    chunk->chunk_counter = 1;

    set_indexes(a);
}

void push_to_b(t_stack **a, t_stack **b, t_chunk *chunk)
{
    t_stack *target;
    int moved;

    while (chunk->chunk_counter <= chunk->chunk_amount)
    {
        moved = 0;

        while (chunk_in_stack(*a, chunk))
        {
            target = find_closest_in_chunk(*a, chunk);
            if (!target)
                break;

            while (target->pos > 0)
            {
                ra(a);
                target->pos--;
            }
            while (target->pos < 0)
            {
                rra(a);
                target->pos++;
            }

            pb(a, b);
            moved++;

            if ((*b)->index < (chunk->chunk_counter * chunk->chunk_length
                               - chunk->chunk_length / 2)
                && (moved <= chunk->chunk_length / 2))
                rb(b);
        }
        chunk->chunk_counter++;
    }
}

// void print_stack(char *name, t_stack *s)
// {
//     printf("%s: ", name);
//     if (!s)
//     {
//         printf("(empty)\n");
//         return;
//     }
//     while (s)
//     {
//         printf("%d[%d] ", s->value, s->index);
//         s = s->next;
//     }
//     printf("\n");
// }

// void free_stack(t_stack **stack)
// {
//     t_stack *current = *stack;
//     t_stack *next;

//     while (current)
//     {
//         next = current->next;
//         free(current);
//         current = next;
//     }
//     *stack = NULL;
// }

// int main_test(void)
// {
//     int arr[] = {9, 8, 5, 2, 6, 7, 1, 3, 4, 10};
//     int size = 10;
//     t_stack *a = NULL;
//     t_stack *b = NULL;
//     t_chunk chunk;

//     printf("=== Testing Turk Algorithm for Push Swap ===\n\n");

//     for (int i = size - 1; i >= 0; i--)
//     {
//         t_stack *n = malloc(sizeof(t_stack));
//         n->value = arr[i];
//         n->size = size;
//         n->index = 0;
//         n->pos = 0;
//         n->target_pos = 0;
//         n->cost_a = 0;
//         n->cost_b = 0;
//         n->next = a;
//         a = n;
//     }

//     printf("Initial state:\n");
//     print_stack("Stack A", a);
//     print_stack("Stack B", b);
//     printf("\n");

//     setup(&a, size, &chunk);
//     printf("Chunk configuration:\n");
//     printf("  Chunk amount: %d\n", chunk.chunk_amount);
//     printf("  Chunk length: %d\n", chunk.chunk_length);
//     printf("\n");

//     printf("After set_indexes:\n");
//     print_stack("Stack A", a);
//     printf("\n");

//     printf("Starting push_to_b...\n");
//     printf("(Operations will be printed as they execute)\n\n");

//     push_to_b(&a, &b, &chunk);

//     printf("\nAfter push_to_b:\n");
//     print_stack("Stack A", a);
//     print_stack("Stack B", b);
//     printf("\n");

//     printf("Starting push_to_a...\n");
//     printf("(Operations will be printed as they execute)\n\n");

//     push_to_a(&a, &b);

//     printf("\nFinal state after push_to_a:\n");
//     print_stack("Stack A", a);
//     print_stack("Stack B", b);
//     printf("\n");

//     check_sorting_result(a, b);

//     free_stack(&a);
//     free_stack(&b);

//     return 0;
// }


