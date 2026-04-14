#include "push_swap.h"

int	stack_min(t_stack *stack)
{
    int min;

    t_stack *tmp;

    tmp = stack;

    if(!tmp)
        return(0);

    min = tmp->value;

    while(tmp)
    {
        if(tmp->value < min)
            min = tmp->value;
        tmp = tmp->next;
    }
    return(min);

}