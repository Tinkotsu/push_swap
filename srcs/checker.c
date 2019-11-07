/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:02:11 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 22:27:27 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_op(t_ps *s, char *str)
{
	if (ft_strequ(str, "pa\n"))
		pa(s, 0);
	else if (ft_strequ(str, "pb\n"))
		pb(s, 0);
	else if (ft_strequ(str, "sa\n"))
		sa(s, 0);
	else if (ft_strequ(str, "sb\n"))
		sb(s, 0);
	else if (ft_strequ(str, "ss\n"))
		ss(s, 0);
	else if (ft_strequ(str, "ra\n"))
		ra(s, 0);
	else if (ft_strequ(str, "rb\n"))
		rb(s, 0);
	else if (ft_strequ(str, "rr\n"))
		rr(s, 0);
	else if (ft_strequ(str, "rra\n"))
		rra(s, 0);
	else if (ft_strequ(str, "rrb\n"))
		rrb(s, 0);
	else if (ft_strequ(str, "rrr\n"))
		rrr(s, 0);
	else
		error();
}

void		checker(t_ps *s)
{
	char	*buff;

	if (!(buff = ft_strnew(4)))
		error();
	while (read(0, buff, 4))
	{
		if (ft_strchr(buff, '\n'))
		{
			check_op(s, buff);
			if (s->debug)
				debug(s);
			ft_strclr(buff);
		}
	}
	free(buff);
	if (!s->stack_a || s->stack_b)
		write(1, "KO\n", 3);
	else if (is_sorted(s->stack_a))
		write(1, "OK\n", 3);
}
