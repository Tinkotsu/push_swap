/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:18:41 by ifran             #+#    #+#             */
/*   Updated: 2019/10/31 16:42:09 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_ps	*s;
	int		i;

	i = 1;
	if (!(s = (t_ps *)malloc(sizeof(t_ps))))
		error();
	s->stack_a = NULL;
	s->stack_b = NULL;
	while (argv[i])
	{
		validate_and_push(argv[i]);
		++i;
	}
	push_swap(s);
//	test(s);
	return (0);
}
