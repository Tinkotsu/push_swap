//HEADER

#include "push_swap.h"

static int			check_stack(t_ps *s)
{
	if (is_sorted(s->stack_a))
		return (1);
	return (0);
}

void		push_swap(t_ps *s)
{
	t_st	*temp;

	if (check_stack(s))
		return ;
	leave_three(s);
	do_index(s);
	
}
