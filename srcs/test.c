#include <stdio.h>
#include "push_swap.h"

void test(t_ps *s)
{
    sa(s);
    while (s->stack_a)
    {
	printf("%d\n", s->stack_a->n);
	s->stack_a = s->stack_a->next;
    }
}
