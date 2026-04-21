#include "push_swap.h"

void	m_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	tmp->prev = NULL;
	*a = tmp;


}
void	m_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	tmp->prev = NULL;
	*b = tmp;


}
