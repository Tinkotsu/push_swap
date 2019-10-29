//HEADER

#include "push_swap.h"

void	ra(t_ps *s)
{
	t_st *temp;

	temp = s->stack_a;
	s->stack_a = s->stack_a->next;
	while (temp->next)
		temp = temp->next;
	temp->next = s->stack_a;
	temp->next->next = NULL;
}

void	rb(t_ps *s)
{
	t_st *temp;

	temp = s->stack_b;
	s->stack_b = s->stack_b->next;
	while (temp->next)
		temp = temp->next;
	temp->next = s->stack_b;
	temp->next->next = NULL;
}

void	rr(t_ps *s)
{
	ra(s);
	rb(s);
}