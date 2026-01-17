#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_stack
{
    int             size; //возможно стоит вынести из структуры но пока что так
    int             value;
    int             index;
    int             pos;
    // int             target_pos;
    int             cost_a;
    int             cost_b;
    struct s_stack  *next;
} t_stack;

// typedef struct s_chunk
// {
//     int chunk_start;
//     int chunks_end;
// } t_chunk

typedef struct s_chunk
{
    // t_chunk chunk;   
    int chunk_counter;
    int chunk_length;
    int chunk_amount;
} t_chunk;

#endif