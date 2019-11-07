/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:30:42 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 18:49:09 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	test(t_ps *s)
{
	t_st *temp_a;
	t_st *temp_b;

	temp_a = s->stack_a;
	temp_b = s->stack_b;
	if (!temp_a && !temp_b)
		return ;
	ft_putstr("PRINTING STACK A\n");
	while (temp_a)
	{
		ft_putnbr(temp_a->n);
		write(1, "\n", 1);
		temp_a = temp_a->next;
	}
	ft_putstr("PRINTING STACK B\n");
	while (temp_b)
	{
		ft_putnbr(temp_b->n);
		write(1, "\n", 1);
		temp_b = temp_b->next;
	}
}
