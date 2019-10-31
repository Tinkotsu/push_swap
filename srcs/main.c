/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:18:41 by ifran             #+#    #+#             */
/*   Updated: 2019/10/31 16:38:24 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	validate(char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	while(*str)
	{
		if (*str < '0' || *str > '9')
			error();
		++str;
	}
}

static void	check_num(char *str, int n)
{
	int minus;

	minus = 0;
	if ((*str == '-' && n > 0) || (*str != '-' && n < 0)) //не работает с max_int x2
		error();
	if (*str == '-' && (minus = 1))
		++str;
	while (*str)
	{
		if (!n && minus && *str != '0')
			error();
		++str;
	}
}

static void	push_elem(char *str, t_ps *s)
{
	t_st	*new;
	t_st	*temp;
	int		num;

	if (!(new = (t_st *)malloc(sizeof(t_st))))
		error();
	num = ft_atoi(str);
	check_num(str, num);
	new->n = num;
	new->next = NULL;
	if (!(s->stack_a))
		s->stack_a = new;
	else
	{
		temp = s->stack_a;
		while (1)
		{
			if (temp->n == num)
				error();
			if (!temp->next)
				break ;
			temp = temp->next;
		}
		temp->next = new;
	}
}

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
		validate(argv[i]);
		push_elem(argv[i], s);
		++i;
	}
	push_swap(s);
//	test(s);
	return (0);
}
