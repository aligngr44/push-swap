#include "push_swap.h"

void sb(t_stack **b)
{
    m_sb(b);
    write(1, "sb\n", 3);
}
void rb(t_stack **b)
{
    m_rb(b);
    write(1, "rb\n", 3);
}
void rrb(t_stack **b)
{
    m_rrb(b);
    write(1, "rrb\n", 4);
}