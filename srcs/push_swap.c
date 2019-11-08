/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:30:30 by ifran             #+#    #+#             */
/*   Updated: 2019/11/08 12:32:06 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_stack(t_ps *s)
{
	if (is_sorted(s->stack_a))
		return (1);
	return (0);
}

static size_t	find_elem(t_ps *s)
{
	t_st	*temp;
	size_t	min_ops;
	size_t	min_ops_i;

	find_ops(s, s->stack_b);
	min_ops = s->stack_b->min_ops;
	min_ops_i = s->stack_b->index;
	temp = s->stack_b->next;
	while (temp)
	{
		find_ops(s, temp);
		if (temp->min_ops < min_ops)
		{
			min_ops = temp->min_ops;
			min_ops_i = temp->index;
		}
		temp = temp->next;
	}
	return (min_ops_i);
}

static void		last_roll(t_ps *s)
{
	int		min;
	size_t	len;
	t_st	*temp;

	temp = s->stack_a;
	len = stack_len(s->stack_a);
	min = find_min(s->stack_a);
	while (temp->n != min)
		temp = temp->next;
	if (temp->index > len / 2 + len % 2)
	{
		while (s->stack_a->n != min)
			rra(s, 1);
	}
	else
	{
		while (s->stack_a->n != min)
			ra(s, 1);
	}
}

void			push_swap(t_ps *s)
{
	size_t i;

	if (check_stack(s))
	{
		s->debug = 0;
		return ;
	}
	leave_three(s);
	while (s->stack_b)
	{
		do_index(s);
		i = find_elem(s);
		do_op(s, i);
	}
	last_roll(s);
}
