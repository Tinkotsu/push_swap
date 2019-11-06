//HEADER

#include "push_swap.h"

static void	sort_three(t_ps *s, int min, int max)
{
	if (s->stack_a->n == min)
	{
		if (s->stack_a->next->n == max)
		{
			sa(s, 1);
			ra(s, 1);
		}
	}
	else if (s->stack_a->n == max)
	{
		if (s->stack_a->next->n == min)
			ra(s, 1);
		else
		{
			ra(s, 1);
			sa(s, 1);
		}
	}
	else
	{
		if (s->stack_a->next->n == min)
			sa(s, 1);
		else
			rra(s, 1);			
	}
}

void		leave_three(t_ps *s)
{
	size_t	len;
	int		min;
	int		max;

	min = find_min(s->stack_a);
	max = find_max(s->stack_a);
	if (!(len = stack_len(s->stack_a)))
		return ;
	while (len > 3)
	{
		while (s->stack_a->n == min || s->stack_a->n == max)
			ra(s, 1);
		pb(s, 1);
		len--;
	}
	sort_three(s, min, max);
}
