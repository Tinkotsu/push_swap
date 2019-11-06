//HEADER

#include "push_swap.h"

static t_st		*initialise(t_ps *s, size_t index)
{
	t_st *temp;

	temp = s->stack_b;
	while (temp->index != index)
		temp = temp->next;
	temp->min_ops = 0;
	temp->type_ops = 0;
	temp->rrs = 0;
	temp->rrrs = 0;
	temp->rbs = 0;
	temp->rrbs = 0;
	temp->ras = 0;
	temp->rras = 0;
	return (temp);
}

static void		find_min_op(t_st *s)
{
	size_t	max_r;
	size_t	max_rr;

	max_r = s->ras > s->rbs ? s->ras : s->rbs;
	max_rr = s->rras > s->rrbs ? s->rras : s->rrbs;
	s->rrs = s->ras > s->rbs ? s->rbs : s->ras;
	s->rrrs = s->rras > s->rrbs ? s->rrbs : s->rras;
	if (max_r <= max_rr && (s->type_ops = 1))
		s->min_ops = max_r;
	else
	{
		s->type_ops = 2;
		s->min_ops = max_rr;
	}
	if (s->rbs + s->rras < s->min_ops && (s->type_ops = 3))
		s->min_ops = s->rbs + s->rras;
	if (s->rrbs + s->ras < s->min_ops && (s->type_ops = 4))
		s->min_ops = s->rrbs + s->ras;
}

static size_t	find_a_index(t_st *temp, t_st *temp_a)
{
	t_st	*head;
	size_t	a_index;
	int		min;

	head = temp_a;
	min = find_min(temp_a);
	while (temp_a->n != min)
		temp_a = temp_a->next;
	a_index = temp_a->index;
	while (temp->n > temp_a->n)
	{
		if (temp_a->next)
		{
			++a_index;
			temp_a = temp_a->next;
		}
		else
		{
			a_index = 1;
			temp_a = head;
		}
	}
	return (a_index);
}

void		find_ops(t_ps *s, size_t index)
{
	t_st	*temp_a;
	t_st	*temp;
	size_t	a_index;
	size_t	len_a;
	size_t	len_b;

	len_a = stack_len(s->stack_a);
	len_b = stack_len(s->stack_b);
	temp_a = s->stack_a;
	temp = initialise(s, index);
	temp->rrbs = len_b > 1 ? len_b - index + 1 : 0;
	temp->rbs = index - 1;
	a_index = find_a_index(temp, temp_a);
	temp->rras = len_a - a_index + 1;
	temp->ras = a_index - 1;
	find_min_op(temp);
}
