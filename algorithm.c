#include "push_swap.h"

// Проверяем, принадлежит ли элемент текущему чанку
int in_chunk(t_stack *node, t_chunk *chunk)
{
    if (chunk->chunk_counter == 1)
        return (node->index <= chunk->chunk_counter * chunk->chunk_length);
    return (node->index > (chunk->chunk_counter - 1) * chunk->chunk_length &&
            node->index <= chunk->chunk_counter * chunk->chunk_length);
}


// Проверяем, есть ли в стеке элементы текущего чанка
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

// Устанавливаем индексы элементов (0..N-1)
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

// Находим ближайший элемент текущего чанка и вычисляем pos
t_stack *find_closest_in_chunk(t_stack *a, t_chunk *chunk)
{
    int i = 0;
    int size = a->size;
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

// Настройка: делим на чанки и расставляем индексы
void setup(t_stack **a, int total_size, t_chunk *chunk)
{
    // Определяем количество чанков
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

// Основная функция: перенос всех элементов из A в B
void push_to_b(t_stack **a, t_stack **b, t_chunk *chunk)
{
    t_stack *target;
    int moved;

    // Проходим по всем чанкам
    while (chunk->chunk_counter <= chunk->chunk_amount)
    {
        moved = 0;

        while (chunk_in_stack(*a, chunk))
        {
            target = find_closest_in_chunk(*a, chunk);
            if (!target)
                break;

            // Вращаем A, чтобы target оказался на вершине
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

            // Переносим элемент в B
            pb(a, b);
            moved++;

            // Для нижней половины чанка делаем rb
            if ((*b)->index < (chunk->chunk_counter * chunk->chunk_length
                               - chunk->chunk_length / 2)
                && (moved <= chunk->chunk_length / 2))
                rb(b);
        }
        // Переходим к следующему чанку
        chunk->chunk_counter++;
    }
}



// int main(){
//     int arr[] = {3, 1, 2, 5, 4, 6, 0, 8, 7, 9};
//     t_stack *stack_a = NULL;
//     t_stack *new_node;
//     for (int i = 0; i < 10; i++)
//     {
//         new_node = (t_stack *)malloc(sizeof(t_stack));
//         new_node->value = arr[i];
//         new_node->next = stack_a;
//         stack_a = new_node;
//     }
//     set_indexes(&stack_a);
//     t_stack *temp = stack_a;
//     int index = 0;
//     while (temp)
//     {
//         if(temp->index == index)
//         {
//             printf("Index %d: Value %d\n", temp->index, temp->value);
//             index++;
//             temp = stack_a;
//         }
//         else
//             temp = temp->next;
//     }
//     return 0;
// }

void print_stack(char *name, t_stack *s)
{
    printf("%s: ", name);
    while (s)
    {
        printf("%d[%d] ", s->value, s->index);
        s = s->next;
    }
    printf("\n");
}


t_stack *new_node(int value, int index, int size)
{
    t_stack *n = malloc(sizeof(t_stack));
    n->value = value;
    n->index = index;
    n->size = size;
    n->next = NULL;
    return n;
}

t_stack *build_stack(int *arr, int *idx, int size)
{
    t_stack *head = NULL;
    t_stack *tmp;

    for (int i = size - 1; i >= 0; i--)
    {
        tmp = new_node(arr[i], idx[i], size);
        tmp->next = head;
        head = tmp;
    }
    return head;
}


int main(void)
{
    int arr[] = {9, 8, 5, 2, 6, 7, 1, 3, 4, 10};
    int size = 10;

    t_stack *a = NULL;
    t_stack *b = NULL;

    // build stack
    for (int i = size - 1; i >= 0; i--)
    {
        t_stack *n = malloc(sizeof(t_stack));
        n->value = arr[i];
        n->size = size;
        n->next = a;
        a = n;
    }

    set_indexes(&a);

    t_chunk chunk;
    if (size <= 20)
        chunk.chunk_amount = 2;
    else
        chunk.chunk_amount = 5;
    chunk.chunk_length = size / chunk.chunk_amount;
    chunk.chunk_counter = 1;

    print_stack("A start", a);
    print_stack("B start", b);

    push_to_b(&a, &b, &chunk);

    print_stack("A end", a);
    print_stack("B end", b);

    return 0;
}

