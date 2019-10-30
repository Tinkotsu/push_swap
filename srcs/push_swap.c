//HEADER

#include "push_swap.h"


static void	leave_three(t_ps *s)
{
	size_t	len;
	int		min;
	int		max;

	min = find_min(s->stack_a);
	max = find_max(s->stack_a);
	len = stack_len(s->stack_a);
	while (len > 3)
	{
		while (s->stack_a->n == min || s->stack_a->n == max)
		{
			ra(s);
			write(1, "ra\n", 3);
		}
		pb(s);
		write(1, "pb\n", 3);
		--len;
	}
}

void		push_swap(t_ps *s)
{
	leave_three(s);
}