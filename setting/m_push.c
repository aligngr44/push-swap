#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
    m_pa(a, b);
    write(1, "pa\n", 3);
}
void	pb(t_stack **a, t_stack **b)
{
    m_pb(a, b);
    write(1, "pb\n", 3);
}