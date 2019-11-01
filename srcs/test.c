#include <stdio.h>
#include "push_swap.h"

void test(t_ps *s)
{
	t_st *temp_a;
	t_st *temp_b;

	temp_a = s->stack_a;
	temp_b = s->stack_b;
	if (!temp_a && !temp_b)
		return ;
	printf("PRINTING STACK A\n");
    while (temp_a)
    {
		printf("%d\n", temp_a->n);
		temp_a = temp_a->next;
    }
	printf("PRINTING STACK B\n");
    while (temp_b)
    {
		printf("%d\n", temp_b->n);
		temp_b = temp_b->next;
    }
}
