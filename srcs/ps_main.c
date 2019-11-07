/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:18:41 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 22:06:44 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_ps	*s;
	int		i;

	if (argc <= 1)
		return (0);
	i = 1;
	if (!(s = (t_ps *)malloc(sizeof(t_ps))))
		error();
	s->stack_a = NULL;
	s->stack_b = NULL;
	s->debug = 0;
	while (argv[i])
	{
		validate_and_push(argv[i], s);
		++i;
	}
	if (s->debug)
		debug(s);
	push_swap(s);
	if (s->debug)
		debug(s);
	all_free(s);
	return (0);
}
