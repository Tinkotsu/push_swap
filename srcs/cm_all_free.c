/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_all_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:52:01 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 17:52:02 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	all_free(t_ps *s)
{
	t_st *temp;

	while (s->stack_a)
	{
		temp = s->stack_a->next;
		free(s->stack_a);
		s->stack_a = temp;
	}
	while (s->stack_b)
	{
		temp = s->stack_a->next;
		free(s->stack_b);
		s->stack_b = temp;
	}
	free(s);
}
