/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_validate_and_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:41:52 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 21:19:15 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static char	*check_first(char *str, int *minus)
{
	if (*str == '+' || (*str == '-' && (*minus = 1)))
		++str;
	if (!*str)
		error();
	while (*str == '0')
		++str;
	return (str);
}

static void	validate(char *str, int n)
{
	size_t	len;
	int		minus;

	minus = 0;
	len = 0;
	str = check_first(str, &minus);
	if (n == 0 && *str && *str != '0')
		error();
	if (!*str)
		return ;
	len = ft_strlen(str);
	if (len > 10)
		error();
	if (len == 10 && !minus && ft_strcmp("2147483647", str) < 0)
		error();
	if (len == 10 && minus && ft_strcmp("2147483648", str) < 0)
		error();
	while (*str)
	{
		if (*str < '0' || *str > '9')
			error();
		++str;
	}
}

static void	push_elem(t_ps *s, char *str)
{
	t_st	*new;
	t_st	*temp;
	int		num;

	if (!(new = (t_st *)malloc(sizeof(t_st))))
		error();
	num = ft_atoi(str);
	validate(str, num);
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

void		validate_and_push(char *str, t_ps *s)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_strsplit_full(str);
	while (split[i])
	{
		push_elem(s, split[i]);
		++i;
	}
	i--;
	ft_freep(split, i);
}
