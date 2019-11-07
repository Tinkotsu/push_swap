/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:52:43 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 21:59:08 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	one(t_ps *s, t_st *temp)
{
	size_t	i;

	i = temp->min_ops;
	while (temp->rrs--)
	{
		i--;
		rr(s, 1);
	}
	if (temp->ras > temp->rbs)
	{
		while (i--)
			ra(s, 1);
	}
	else
	{
		while (i--)
			rb(s, 1);
	}
	pa(s, 1);
}

static void	two(t_ps *s, t_st *temp)
{
	size_t	i;

	i = temp->min_ops;
	while (temp->rrrs--)
	{
		i--;
		rrr(s, 1);
	}
	if (temp->rras > temp->rrbs)
	{
		while (i--)
			rra(s, 1);
	}
	else
	{
		while (i--)
			rrb(s, 1);
	}
	pa(s, 1);
}

static void	three(t_ps *s, t_st *temp)
{
	size_t i;

	i = temp->min_ops;
	while (temp->rbs--)
	{
		i--;
		rb(s, 1);
	}
	while (i--)
		rra(s, 1);
	pa(s, 1);
}

static void	four(t_ps *s, t_st *temp)
{
	size_t i;

	i = temp->min_ops;
	while (temp->rrbs--)
	{
		i--;
		rrb(s, 1);
	}
	while (i--)
		ra(s, 1);
	pa(s, 1);
}

void		do_op(t_ps *s, size_t i)
{
	t_st *temp;

	temp = s->stack_b;
	while (temp->index != i)
		temp = temp->next;
	if (temp->type_ops == 1)
		one(s, temp);
	else if (temp->type_ops == 2)
		two(s, temp);
	else if (temp->type_ops == 3)
		three(s, temp);
	else if (temp->type_ops == 4)
		four(s, temp);
	if (s->debug)
		debug(s);
}
