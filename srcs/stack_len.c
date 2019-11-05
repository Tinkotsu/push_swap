#include "push_swap.h"

size_t	stack_len(t_st *stack)
{
	t_st	*temp;
	size_t	len;

	len = 0;
	temp = stack;
	while (temp)
	{
		++len;
		temp = temp->next;
	}
	return (len);
}