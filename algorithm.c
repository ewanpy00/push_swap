#include "push_swap.h"

void count_cost();

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