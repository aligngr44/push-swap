#include "push_swap.h"

void	m_sa(t_stack **a)
{
	t_stack	*one;
	t_stack	*two;

	if (!a || !*a || !(*a)->next)
		// stack boş veya tek elemanlıysa swap yapılmaz
		return ;
	one = *a;
	two = (*a)->next;
	one->next = two->next;
	if (two->next) // üçüncü eleman varsa prev bağlantısını düzelt
		two->next->prev = one;
	two->next = one;
	two->prev = NULL; // yeni head olacak
	one->prev = two;
	*a = two; // stack başını güncelle


	
}

void	m_ra(t_stack **a)
{
	t_stack	*one;
	t_stack	*lst;

	if (!a || !*a || !(*a)->next) // rotate için en az 2 eleman gerekir
		return ;
	one = *a;        // eski head
	*a = (*a)->next; // yeni head
	(*a)->prev = NULL;
	one->next = NULL;
	lst = stack_last(*a); // listenin sonunu bul
	lst->next = one;      // eski head'i sona koy
	one->prev = lst;



	
}

void	m_rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*new_last;

	if (!a || !*a || !(*a)->next) // reverse rotate için kontrol
		return ;
	last = stack_last(*a); // son eleman
	new_last = last->prev; // yeni son eleman
	new_last->next = NULL;
	last->next = *a; // eski head'i last'in arkasına bağla
	(*a)->prev = last;
	last->prev = NULL; // last yeni head olacak
	*a = last;


	
}
