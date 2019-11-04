//HEADER

#include "push_swap.h"

void		do_index(t_ps *s)
{
	t_st	*temp_a;
	t_st	*temp_b;
	size_t	index;

	temp_a = s->stack_a;
	temp_b = s->stack_b;
	index = 1;
	while (temp_a)
	{
		temp_a->index = index;
		temp_a = temp_a->next;
		++index;
	}
	index = 1;
	while (temp_b)
	{
		temp_b->index = index;
		temp_b = temp_b->next;
		++index;
	}
}