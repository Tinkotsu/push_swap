//HEADER

#include "push_swap.h"

void	sa(t_ps *s)
{
	t_st *temp;

	if (s->stack_a && s->stack_a->next)
	{
		temp = s->stack_a->next->next;
		s->stack_a->next->next = s->stack_a;
		s->stack_a->next = temp;
	}
}

void	sb(t_ps *s)
{
	t_st *temp;

	if (s->stack_b && s->stack_b->next)
	{
		temp = s->stack_b->next->next;
		s->stack_b->next->next = s->stack_b;
		s->stack_b->next = temp;
	}
}

void	ss(t_ps *s)
{
	sa(s);
	sb(s);
}
