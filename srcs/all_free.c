//HEADER

#include "checker.h"
#include "push_swap.h"

void	all_free(t_ps *s)
{
	t_st *temp;

	while (s->stack_a)
	{
		temp = s->stack_a->next;
		free(s->stack_a);
		s->stack_a = temp;
	}
	while (s->stack_b)
	{
		temp = s->stack_a->next;
		free(s->stack_b);
		s->stack_b = temp;
	}
	free(s);
}
