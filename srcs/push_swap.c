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

static void	add_elem(char *str, t_ps *s)
{
	t_st	*new;
	t_st	*temp;
	int		num;

	if (!(new = (t_st *)malloc(sizeof(t_st))))
		error();
	num = ft_atoi(str);
	new->n = num;
	new->next = NULL;
	if (!(s->stack_a))
		s->stack_a = new;
	else
	{
		temp = s->stack_a;
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
	t_ps	*s;
	int		i;
	int		n;

	i = 1;
	if (!(s = (t_ps *)malloc(sizeof(t_ps))))
		error();
	s->stack_a = NULL;
	s->stack_b = NULL;
	while (argv[i])
	{
		validate(argv[i]);
		add_elem(argv[i], s);
		++i;
	}
	while (s->stack_a)
	{
		n = s->stack_a->n;
		printf("%d\n", n);
		s->stack_a = s->stack_a->next;
	}
	return (0);
}
