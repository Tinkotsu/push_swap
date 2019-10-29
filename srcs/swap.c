//HEADER

#include "push_swap.h"
/*
void	sa(t_ps *s)
{
	t_st *temp1;
	t_st *temp2;

	if (s->stack_a && s->stack_a->next)
	{
		temp1 = s->stack_a;
		temp2 = s->stack_a->next;
		temp1->next = temp2->next;
		s->stack_a = temp2;
		s->stack_a->next = temp1;
	}
}

void	sb(t_ps *s)
{
	t_st *temp1;
	t_st *temp2;

	if (s->stack_b && s->stack_b->next)
	{
		temp1 = s->stack_b;
		temp2 = s->stack_b->next;
		temp1->next = temp2->next; //s->stack_b->next->next
		s->stack_b = temp2;//s->stack->b->next
		s->stack_b->next = temp1;//temp
	}
}
*/

void	sa(t_ps *s)
{
	t_st *temp;

	if (s->stack_a && s->stack_a->next)
	{
		temp = s->stack_a;
		temp->next = s->stack_a->next->next;
		s->stack_a = s->stack_a->next;
		s->stack_a->next = temp;
	}
}

void	sa(t_ps *s)
{
	t_st *temp;

	if (s->stack_b && s->stack_b->next)
	{
		temp = s->stack_b;
		temp->next = s->stack_b->next->next;
		s->stack_b = s->stack_b->next;
		s->stack_b->next = temp;
	}
}

void	ss(t_ps *s)
{
	sa(s);
	sb(s);
}
