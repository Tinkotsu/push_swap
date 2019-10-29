#include "push_swap.h"

void	pa(t_ps *s)
{
	t_st *temp;

	if (s->stack_b)
	{
		temp = s->stack_b->next;
		s->stack_b->next = s->stack_a;
		s->stack_a = s->stack_b;
		s->stack_b = temp;
	}
}

void	pb(t_ps *s)
{
	t_st *temp;

	if (s->stack_a)
	{
		temp = s->stack_a->next;
		s->stack_a->next = s->stack_b;
		s->stack_b = s->stack_a;
		s->stack_a = temp;
	}
}
