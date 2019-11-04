//HEADER

#include "push_swap.h"

static void	sort_three(t_ps *s, int min, int max) //оставляю max min val
{
	if (s->stack_a->n == min)
	{
		if (s->stack_a->next->n == max)
		{
			sa(s);
			ra(s);
		}
	}
	if (s->stack_a->n == max)
	{
		if (s->stack_a->next->n == min)
			ra(s);
		else
		{
			sa(s);
			rra(s);
		}
	}
	else
	{
		if (s->stack_a->next->n == min)
			sa(s);
		else
			rra(s);			
	}
}

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

void		leave_three(t_ps *s)
{
	size_t	len;
	int		min;
	int		max;

	min = find_min(s->stack_a);
	max = find_max(s->stack_a);
	if (!(len = stack_len(s->stack_a)))
		return ;
	while (len > 3) //или если стек А отсортирован
	{
		while (s->stack_a->n == min || s->stack_a->n == max)
			ra(s);
		pb(s);
		len--;
	}
	sort_three(s, min, max);
	do_index(s);
}
