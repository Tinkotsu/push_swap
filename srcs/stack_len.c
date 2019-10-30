#include "push_swap.h"

size_t	stack_len(t_st *stack_a)
{
	t_st	*temp;
	size_t	len;

	len = 0;
	temp = stack_a;
	while (temp)
	{
		++len;
		temp = temp->next;
	}
	return (len);
}