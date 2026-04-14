#include "push_swap.h"

int	find_position(t_stack *stack, int value)
{
    int position;

    t_stack *tmp;

    tmp = stack;

    position = 0;
    while(tmp)
    {
        if(tmp->value == value)
            return(position);
        tmp = tmp->next;
        position++;
    }
    return 1;
}