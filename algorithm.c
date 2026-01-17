#include "push_swap.h"

void to_stack_b(t_stack **stack_a, t_stack **stack_b);

void to_stack_a(t_stack **stack_a, t_stack **stack_b);

void set_pos(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk){
    int i;
    t_stack *tmp; 

    i = 0;
    tmp = stack_a;
    while(tmp){
        if(stack_a->index <= chunk_counter * chunks_length)
        {
            if(i <= stack_a->size / 2)
                tmp->pos = i;
            else
                tmp->pos = i - stack_a->size;
        }
        tmp = tmp->next;
        i++;
    }    
}

void cost(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
    t_stack *tmp;

    tmp = stack_a;
    while(tmp)
    {
        if(stack_a->pos <= stack_a->size / 2)
            cost = pos;
        else
            cost = pos-size;
        tmp = tmp->next;
    }
}
void set_chunks(t_stack *stack_a, t_stack *stack_b, int total_size){
    t_chunk chunk;

    if(size >= 0 && size <= 20)
        chunk->chunks_amount = 2;
    else if(size > 20 && size <= 100)
        chunk->chunks_amount = 5; // 4 =5 
    else if(size > 100 && size <= 500)
        chunk->chunks_amount = 10; //5 - 10
    else if(size > 500)
        chunk->chunks_amount = 20; // ??
    chunk->chunks_length = size / chunk.chunks_amount;
    chunk->chunk_counter = 1;
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

int main(){
    int arr[] = {3, 1, 2, 5, 4, 6, 0, 8, 7, 9};
    t_stack *stack_a = NULL;
    t_stack *new_node;
    for (int i = 0; i < 10; i++)
    {
        new_node = (t_stack *)malloc(sizeof(t_stack));
        new_node->value = arr[i];
        new_node->next = stack_a;
        stack_a = new_node;
    }
    set_indexes(&stack_a);
    t_stack *temp = stack_a;
    int index = 0;
    while (temp)
    {
        if(temp->index == index)
        {
            printf("Index %d: Value %d\n", temp->index, temp->value);
            index++;
            temp = stack_a;
        }
        else
            temp = temp->next;
    }
    return 0;
}