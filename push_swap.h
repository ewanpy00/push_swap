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


#endif
