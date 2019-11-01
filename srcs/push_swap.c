//HEADER

#include "push_swap.h"

static void	sort_three(t_ps *s, int min, int max)
{
	if (s->stack_a->n == min)
	{
		if (s->stack_a->next->n == max)
		{
			sa(s);
			rra(s);
		}
		else
			ra(s);
	}
	if (s->stack_a->n == max)
	{
		if (s->stack_a->next->n == min)
			rra(s);
		else
			sa(s);
	}
	else
	{
		if (s->stack_a->next->n == min)
		{
			sa(s);
			ra(s);
		}
	}
}

static void	leave_three(t_ps *s)
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
		if (s->stack_a->n == min)
			ra(s);
		if (s->stack_a->n == max)
			ra(s);
		pb(s);
		len--;
	}
	sort_three(s->stack_a, min, max);
}

int			check_stack(t_ps *s)
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
	if (!(check_stack(s)))
		leave_three(s);
}
