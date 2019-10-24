/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:18:41 by ifran             #+#    #+#             */
/*   Updated: 2019/10/24 18:12:04 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	validate(char *str)
{
	while(*str)
	{
		if (*str < '0' || *str > '9')
			error();
		++str;
	}
}

static void	add_elem(char *str, t_ps *ps)
{
	t_st	*new;
	t_st	*temp;
	int		num;

	if (!(new = (t_st *)malloc(sizeof(t_st))))
		error();
	num = ft_atoi(str);
	new->n = num;
	new->next = NULL;
	if (!(ps->stack_a))
		ps->stack_a = new;
	else
	{
		temp = ps->stack_a;
		while (temp->next)
		{
			if (temp->n == num || temp->next->n == num)
				error();
			temp = temp->next;
		}
		temp->next = new;
	}
}

int			main(int argc, char **argv)
{
	t_ps	*ps;
	int		i;

	i = 1;
	if (!(ps = (t_ps *)malloc(sizeof(t_ps))))
		error();
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	while (argv[i])
	{
		validate(argv[i]);
		add_elem(argv[i], ps);
		++i;
	}
	//поехали делать всё остальное, что нужно
	return (0);
}
