/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:02:11 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 18:02:12 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_op(t_ps *s, char *str, int i)
{
	if (i == 3 && ft_strequ(str, "pa\n"))
		pa(s, 0);
	else if (i == 3 && ft_strequ(str, "pb\n"))
		pb(s, 0);
	else if (i == 3 && ft_strequ(str, "sa\n"))
		sa(s, 0);
	else if (i == 3 && ft_strequ(str, "sb\n"))
		sb(s, 0);
	else if (i == 3 && ft_strequ(str, "ss\n"))
		ss(s, 0);
	else if (i == 3 && ft_strequ(str, "ra\n"))
		ra(s, 0);
	else if (i == 3 && ft_strequ(str, "rb\n"))
		rb(s, 0);
	else if (i == 3 && ft_strequ(str, "rr\n"))
		rr(s, 0);
	else if (i == 4 && ft_strequ(str, "rra\n"))
		rra(s, 0);
	else if (i == 4 && ft_strequ(str, "rrb\n"))
		rrb(s, 0);
	else if (i == 4 && ft_strequ(str, "rrr\n"))
		rrr(s, 0);
	else
		error();
}

void		checker(t_ps *s)
{
	char	*buff;
	int		i;

	i = 0;
	if (!(buff = ft_strnew(4)))
		error();
	while (read(0, buff, 1))
	{
		if (i > 4)
			error();
		if (i > 2 && ft_strchr(buff, '\n'))
		{
			check_op(s, buff, i);
			ft_strclr(buff);
			i = 0;
		}
		++i;
	}
	if (i)
		error();
	if (!s->stack_b && is_sorted(s->stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
