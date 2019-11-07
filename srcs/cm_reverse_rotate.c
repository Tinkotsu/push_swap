/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:25:13 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 21:24:50 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rra(t_ps *s, int flag)
{
	t_st *head;
	t_st *tail;

	if (!s->stack_a)
		return ;
	head = s->stack_a;
	while (head->next)
	{
		tail = head;
		head = head->next;
	}
	tail->next = NULL;
	head->next = s->stack_a;
	s->stack_a = head;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_ps *s, int flag)
{
	t_st *head;
	t_st *tail;

	if (!s->stack_b)
		return ;
	head = s->stack_b;
	while (head->next)
	{
		tail = head;
		head = head->next;
	}
	tail->next = NULL;
	head->next = s->stack_b;
	s->stack_b = head;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_ps *s, int flag)
{
	rra(s, 0);
	rrb(s, 0);
	if (flag)
		write(1, "rrr\n", 4);
}
