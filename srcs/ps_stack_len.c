/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:53:17 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 17:53:18 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_len(t_st *stack)
{
	t_st	*temp;
	size_t	len;

	len = 0;
	temp = stack;
	while (temp)
	{
		++len;
		temp = temp->next;
	}
	return (len);
}
