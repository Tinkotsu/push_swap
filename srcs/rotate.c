//HEADER

#include "push_swap.h"

void	ra(t_ps *s, int flag)
{
	t_st *temp;

	temp = s->stack_a;
	while (temp->next)
		temp = temp->next;
	temp->next = s->stack_a;
	s->stack_a = s->stack_a->next;
	temp->next->next = NULL;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_ps *s, int flag)
{
	t_st *temp;

	temp = s->stack_b;
	while (temp->next)
		temp = temp->next;
	temp->next = s->stack_b;
	s->stack_b = s->stack_b->next;
	temp->next->next = NULL;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_ps *s, int flag)
{
	ra(s, 0);
	rb(s, 0);
	if (flag)
		write(1, "rr\n", 3);
}
