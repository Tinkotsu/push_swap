/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:30:42 by ifran             #+#    #+#             */
/*   Updated: 2019/11/09 21:08:13 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void		put(t_st *temp_a, t_st *temp_b)
{
	while (temp_a || temp_b)
	{
		ft_putchar('\t');
		if (temp_a)
		{
			ft_putnbr(temp_a->n);
			temp_a = temp_a->next;
		}
		ft_putstr("\t    |\t");
		if (temp_b)
		{
			ft_putchar('\t');
			ft_putnbr(temp_b->n);
			temp_b = temp_b->next;
		}
		write(1, "\n", 1);
	}
}

void			debug(t_ps *s)
{
	t_st *temp_a;
	t_st *temp_b;

	temp_a = s->stack_a;
	temp_b = s->stack_b;
	if (!temp_a && !temp_b)
		return ;
	ft_putstr("------------------------------------------");
	ft_putstr("\nPRINTING STACK A:\tPRINTING STACK B:\n\n");
	put(temp_a, temp_b);
	ft_putstr("------------------------------------------\n");
}
