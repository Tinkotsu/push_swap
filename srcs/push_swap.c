//HEADER

#include "push_swap.h"

static void	sort_three(t_ps *s, int min, int max)
{
	if (!(is_sorted(s->stack_a) || is_r_sorted(s->stack_a)))
	{
		if (s->stack_a->n == max || s->stack_a->n == min)
		{
			ra(s);
			write(1, "ra\n", 3);
		}
		else 
		{
			rra(s);
			write(1, "rra\n", 4);
		}
	}
}

static void	leave_three(t_ps *s)
{
	size_t	len;
	int		min;
	int		max;

	min = find_min(s->stack_a);
	max = find_max(s->stack_a);
	if (!(len = stack_len(s->stack_a)))
		return ;
	while (len > 3)
	{
		if (s->stack_a->n == min)
		{
			ra(s);
			write(1, "ra\n", 3);
		}
		if (s->stack_a->n == max)
		{
			ra(s);
			write(1, "ra\n", 3);
		}
		pb(s);
		write(1, "pb\n", 3);
		len--;
	}
	sort_three(s, min, max);
}

int			check_stack(t_st *s)
{
	int min;

	if (is_sorted(s))
		return (1);
	if (is_r_sorted(s))
	{
		min = find_min(s);
		while (s->n != min)
		{
			ra(s);
			write(1, "ra\n", 3);
		}
		return (1);
	}
	return (0);
}

void		push_swap(t_ps *s)
{
	if (!(check_stack(s->stack_a)))
		leave_three(s);
}