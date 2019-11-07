/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:24:01 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 17:52:28 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_ps *s, int flag)
{
	t_st *temp1;
	t_st *temp2;

	if (s->stack_a && s->stack_a->next)
	{
		temp1 = s->stack_a;
		temp2 = s->stack_a->next;
		temp1->next = temp2->next;
		s->stack_a = temp2;
		s->stack_a->next = temp1;
	}
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_ps *s, int flag)
{
	t_st *temp1;
	t_st *temp2;

	if (s->stack_b && s->stack_b->next)
	{
		temp1 = s->stack_b;
		temp2 = s->stack_b->next;
		temp1->next = temp2->next;
		s->stack_b = temp2;
		s->stack_b->next = temp1;
	}
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_ps *s, int flag)
{
	sa(s, 0);
	sb(s, 0);
	if (flag)
		write(1, "ss\n", 3);
}
