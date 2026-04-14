#include "push_swap.h"

int stack_size(t_stack *stack)
{
    t_stack *tmp;

    int count;

    tmp = stack;

    count = 0;
    while(tmp)
    {
        count++;
        tmp = tmp->next;
    }
    return(count);
}
