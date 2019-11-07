/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:23:38 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 17:52:18 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	pa(t_ps *s, int flag)
{
	t_st *temp;

	if (s->stack_b)
	{
		temp = s->stack_b->next;
		s->stack_b->next = s->stack_a;
		s->stack_a = s->stack_b;
		s->stack_b = temp;
	}
	if (flag)
		write(1, "pa\n", 3);
}

void	pb(t_ps *s, int flag)
{
	t_st *temp;

	if (s->stack_a)
	{
		temp = s->stack_a->next;
		s->stack_a->next = s->stack_b;
		s->stack_b = s->stack_a;
		s->stack_a = temp;
	}
	if (flag)
		write(1, "pb\n", 3);
}
