#include "push_swap.h"

int		is_r_sorted(t_st *stack)
{
	t_st *temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->next->n > temp->n)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int		is_sorted(t_st *stack)
{
	t_st *temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->next->n < temp->n)
			return (0);
		temp = temp->next;
	}
	return (1);
}
