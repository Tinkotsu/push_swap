//HEADER

#include "push_swap.h"

static int check_stack(t_ps *s)
{
	if (is_sorted(s->stack_a))
		return (1);
	return (0);
}

static size_t find_elem(t_ps *s)
{
	t_st *temp;
	size_t min_ops;
	size_t min_ops_i;

	temp = s->stack_b;
	min_ops = temp->min_ops;
	min_ops_i = temp->index;
	while (temp)
	{
		find_ops(s, temp->index);
		if (temp->min_ops < min_ops)
		{
			min_ops = temp->min_ops;
			min_ops_i = temp->index;
		}
		temp = temp->next;
	}
	return (min_ops_i);
}



void push_swap(t_ps *s)
{
	size_t i;

	if (check_stack(s))
		return;
	leave_three(s);
	while (s->stack_b)
	{
		do_index(s);
		i = find_elem(s);
		do_op(i, s);
	}
}
