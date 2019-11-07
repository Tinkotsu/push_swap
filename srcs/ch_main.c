/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:45:07 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 22:29:07 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	int		i;
	t_ps	*s;

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
	if (s->debug && i == 2)
		return (0);
	if (s->debug)
		debug(s);
	checker(s);
	all_free(s);
	return (0);
}
