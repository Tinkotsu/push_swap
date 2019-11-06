//HEADER

#include "push_swap.h"

void	rra(t_ps *s, int flag)
{
	t_st *head;
	t_st *tail;

	head = s->stack_a;
	while (head->next)
	{
		tail = head;
		head = head->next;
	}
	tail->next = NULL;
	head->next = s->stack_a;
	s->stack_a = head;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_ps *s, int flag)
{
	t_st *head;
	t_st *tail;

	head = s->stack_b;
	while (head->next)
	{
		tail = head;
		head = head->next;
	}
	tail->next = NULL;
	head->next = s->stack_b;
	s->stack_b = head;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_ps *s)
{
	rra(s, 0);
	rrb(s, 0);
	write(1, "rrr\n", 4);
}
