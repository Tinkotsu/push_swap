//HEADER

#include "push_swap.h"

static void one(t_ps *s, t_st *temp)
{
	size_t	i;

	i = temp->min_ops;
	while (temp->rrs--)
	{
		i--;
		rr(s);
	}
	if (temp->ras > temp->rbs)
	{
		while (i--)
			ra(s);
	}
	else
	{
		while (i--)
			rb(s);
	}
	pa(s);
}

static void two(t_ps *s, t_st *temp)
{
	size_t	i;

	i = temp->min_ops;
	while (temp->rrrs--)
	{
		i--;
		rrr(s);
	}
	if (temp->rras > temp->rrbs)
	{
		while (i--)
			rra(s);
	}
	else
	{
		while (i--)
			rrb(s);
	}
	pa(s);
}

static void three(t_ps *s, t_st *temp)
{
	size_t i;

	i = temp->min_ops;
	while (temp->rbs--)
	{
		i--;
		rb(s);
	}
	while (i--)
		rra(s);
	pa(s);
}

static void four(t_ps *s, t_st *temp)
{
	size_t i;

	i = temp->min_ops;
	while (temp->rrbs--)
	{
		i--;
		rrb(s);
	}
	while (i--)
		ra(s);
	pa(s);
}

void	do_op(t_ps *s, size_t i)
{
	t_st *temp;

	temp = s->stack_b;
	while (temp->index != i)
		temp = temp->next;
	if (temp->type_ops == 1)
		one(s, temp);
	else if (temp->type_ops == 2)
		two(s, temp);
	else if (temp->type_ops == 3)
		three(s, temp);
	else if (temp->type_ops == 4)
		four(s, temp);
}
