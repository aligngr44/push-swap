#include "push_swap.h"

int	stack_max(t_stack *stack)
{
    int max;

    t_stack *tmp;

    tmp = stack;

    if(!tmp)
        return(0);

    max = tmp->value;

    while(tmp)
    {
        if(tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
    return(max);

}