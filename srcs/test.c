#include <stdio.h>
#include "push_swap.h"

void test(t_ps *s)
{
	t_st *temp;

	temp = s->stack_a;
	if (!temp)
		return ;
    while (temp)
    {
		printf("%d\n", temp->n);
		temp = temp->next;
    }
}
