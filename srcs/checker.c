/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:02:11 by ifran             #+#    #+#             */
/*   Updated: 2019/11/08 13:16:43 by tinkotsu         ###   ########.fr       */
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
	int		i;

	if (!(buff = ft_strnew(4)))
		error();
	i = 0;
	while (read(0, buff, 1))
	{
		++i;
		++buff;
		if (*(buff - 1) == '\n')
		{
			buff -= i;
			check_op(s, buff);
			if (s->debug)
				debug(s);
			ft_strclr(buff);
			i = 0;
		}
	}
	free(buff);
	if (is_sorted(s->stack_a) && !s->stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
