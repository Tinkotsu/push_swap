/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:34 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 21:54:39 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H

# define COMMON_H

# include "libft.h"

typedef	struct	s_st
{
	size_t		index;
	int			n;
	int			type_ops;
	size_t		min_ops;
	size_t		rrs;
	size_t		rrrs;
	size_t		rrbs;
	size_t		rbs;
	size_t		ras;
	size_t		rras;
	struct s_st	*next;
}				t_st;

typedef struct	s_ps
{
	t_st	*stack_a;
	t_st	*stack_b;
	int		debug;
}				t_ps;

void			all_free(t_ps *s);
void			validate_and_push(char *str, t_ps *s);
int				is_sorted(t_st *stack);
void			error(void);
void			pa(t_ps *s, int flag);
void			pb(t_ps *s, int flag);
void			sa(t_ps *s, int flag);
void			sb(t_ps *s, int flag);
void			ss(t_ps *s, int flag);
void			ra(t_ps *s, int flag);
void			rb(t_ps *s, int flag);
void			rr(t_ps *s, int flag);
void			rra(t_ps *s, int flag);
void			rrb(t_ps *s, int flag);
void			rrr(t_ps *s, int flag);
void			test(t_ps *s);

#endif
