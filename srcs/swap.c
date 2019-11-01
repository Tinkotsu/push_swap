//HEADER

#include "push_swap.h"

void	sa(t_ps *s)
{
	t_st *temp1;
	t_st *temp2;

	if (s->stack_a && s->stack_a->next)
	{
		temp1 = s->stack_a;
		temp2 = s->stack_a->next;
		temp1->next = temp2->next;
		s->stack_a = temp2;
		s->stack_a->next = temp1;
	}
	write(1, "sa\n", 3);
}

void	sb(t_ps *s)
{
	t_st *temp1;
	t_st *temp2;

	if (s->stack_b && s->stack_b->next)
	{
		temp1 = s->stack_b;
		temp2 = s->stack_b->next;
		temp1->next = temp2->next;
		s->stack_b = temp2;
		s->stack_b->next = temp1;
	}
	write(1, "sb\n", 3);
}

void	ss(t_ps *s)
{
	sa(s);
	sb(s);
}
