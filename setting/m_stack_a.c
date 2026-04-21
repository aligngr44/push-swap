#include "push_swap.h"

void	sa(t_stack **a)
{
    m_sa(a);
    write(1, "sa\n", 3);
}
void ra(t_stack **a)
{
    m_ra(a);
    write(1, "ra\n", 3);
}
void rra(t_stack **a)
{
    m_rra(a);
    write(1, "rra\n", 4);
}