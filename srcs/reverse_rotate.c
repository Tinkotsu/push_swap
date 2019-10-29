//HEADER

#include "push_swap.h"

void	rra(t_ps *s)
{
	t_st *temp;
	t_st *prev;

	temp = s->stack_a;
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	temp->next = s->stack_a;
	s->stack_a = temp;
}

void	rrb(t_ps *s)
{
	t_st *temp;
	t_st *prev;

	temp = s->stack_b;
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	temp->next = s->stack_b;
	s->stack_b = temp;
}

void	rrr(t_ps *s)
{
	rra(s);
	rrb(s);
}