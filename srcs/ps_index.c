/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:53:02 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 17:53:03 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_index(t_ps *s)
{
	t_st	*temp_a;
	t_st	*temp_b;
	size_t	index;

	temp_a = s->stack_a;
	temp_b = s->stack_b;
	index = 1;
	while (temp_a)
	{
		temp_a->index = index;
		temp_a = temp_a->next;
		++index;
	}
	index = 1;
	while (temp_b)
	{
		temp_b->index = index;
		temp_b = temp_b->next;
		++index;
	}
}
