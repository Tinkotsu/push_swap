#include "push_swap.h"

int		find_min(t_st *stack)
{
	t_st	*temp;
	int		min;

	temp = stack;
	min = 2147483647;
	while (temp)
	{
		if (temp->n < min)
			min = temp->n;
		temp = temp->next;
	}
	return (min);
}

int		find_max(t_st *stack)
{
	t_st	*temp;
	int		max;

	temp = stack;
	max = -2147483648;
	while (temp)
	{
		if (temp->n > max)
			max = temp->n;
		temp = temp->next;
	}
	return (max);
}