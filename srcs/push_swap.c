//HEADER

#include "push_swap.h"

static int			check_stack(t_ps *s)
{
	t_st *last;

	if (is_sorted(s->stack_a))
		return (1);
	if (is_r_sorted(s->stack_a))
	{
		last = s->stack_a;
		while (last->next)
			last = last->next;
		while (s->stack_a != last)
			ra(s);
		return (1);
	}
	return (0);
}

void		push_swap(t_ps *s)
{
	int		head;
	int		last;
	t_st	*temp;

	if (check_stack(s))
		return ;
	leave_three(s);
	head = s->stack_a->next->next->n;
	while (s->stack_b)
	{
		; // todo
	}
	while (s->stack_a->n != head)
		rra(s);
}
