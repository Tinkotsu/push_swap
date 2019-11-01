/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:18:41 by ifran             #+#    #+#             */
/*   Updated: 2019/11/02 02:18:19 by tinkotsu         ###   ########.fr       */
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
	while (argv[i])
	{
		validate_and_push(argv[i], s);
		++i;
	}
	push_swap(s);
//	test(s);
	return (0);
}
