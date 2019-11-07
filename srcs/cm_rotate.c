/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:24:56 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 17:52:25 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ra(t_ps *s, int flag)
{
	t_st *temp;

	temp = s->stack_a;
	while (temp->next)
		temp = temp->next;
	temp->next = s->stack_a;
	s->stack_a = s->stack_a->next;
	temp->next->next = NULL;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_ps *s, int flag)
{
	t_st *temp;

	temp = s->stack_b;
	while (temp->next)
		temp = temp->next;
	temp->next = s->stack_b;
	s->stack_b = s->stack_b->next;
	temp->next->next = NULL;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_ps *s, int flag)
{
	ra(s, 0);
	rb(s, 0);
	if (flag)
		write(1, "rr\n", 3);
}
