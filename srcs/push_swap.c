/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:18:41 by ifran             #+#    #+#             */
/*   Updated: 2019/10/24 17:54:14 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	validate(char *str)
{
	while(str)
	{
		if (*str < '0' || *str > '9')
			error();
		++str;
	}
}

static void	add_elem(char *str, t_ps *ps)
{
	t_st *new;
	t_st *temp;

	if (!(new = (t_st *)malloc(sizeof(t_st))))
		error();
	new->n = ft_atoi(str);
	new->next = NULL;
	if (!(ps->stack_a))
		ps->stack_a = new;
	else
	{
		temp = ps->stack_a;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int			main(char **argv, int argc)
{
	t_ps	*ps;

	if (!(ps = (t_ps *)malloc(sizeof(t_ps))))
		error();
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	while (*argv)
	{
		validate(*argv);
		add_elem(*argv, ps);
		++argv;
	}
	return (0);
}
