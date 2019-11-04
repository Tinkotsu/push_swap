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

static void	from_b_to_a(t_ps *s, size_t len, int min, int max)
{
	int		head;
	int		tail;
	t_st	*temp;

	while (len > 3)
	{
		while (s->stack_a->n == min || s->stack_a->n == max)
			ra(s);
		temp = s->stack_b;
		if (!s->stack_b || s->stack_a->n > s->stack_b->n)
		{
			pb(s);
			head = s->stack_b->n;
			while (temp->next)
				temp = temp->next;
			tail = temp->n; 
		}
		else // число а меньше, чем б
		{
			;
		}
		len--;
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
<<<<<<< HEAD
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
=======
	from_b_to_a(s, len, min, max);
	sort_three(s, min, max);
}
>>>>>>> 95f4370a485d2e564d32dca38e71c9fd8a3645a4
