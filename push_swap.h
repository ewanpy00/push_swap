#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
    int             size;       
    int             value;      
    int             index;      
    int             pos;       
    int             target_pos;
    int             cost_a;    
    int             cost_b;    
    struct s_stack  *next;
}   t_stack;

typedef struct s_chunk
{
    int chunk_counter;
    int chunk_length;    
    int chunk_amount;    
}   t_chunk;

void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);

void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);

void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);

void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

int stack_size(t_stack *a);
void set_indexes(t_stack **stack_a);
void setup(t_stack **a, int total_size, t_chunk *chunk);
void push_to_b(t_stack **a, t_stack **b, t_chunk *chunk);
void push_to_a(t_stack **a, t_stack **b);
void check_sorting_result(t_stack *a, t_stack *b);

#endif
