/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:23:13 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 17:23:17 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "checker.h"

int		is_sorted(t_st *stack)
{
	t_st *temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->next->n < temp->n)
			return (0);
		temp = temp->next;
	}
	return (1);
}
