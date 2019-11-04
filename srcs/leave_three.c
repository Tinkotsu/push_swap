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

void		do_index(t_st *stack)
{
	t_st	*temp;
	size_t	index;

	temp = stack;
	index = 1;
	while (temp)
	{
		temp->index = index;
		temp = temp->next;
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
	do_index(s->stack_a);
	do_index(s->stack_b);
}
