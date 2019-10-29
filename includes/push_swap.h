/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:31:03 by ifran             #+#    #+#             */
/*   Updated: 2019/10/24 18:03:53 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_st //структура стэка
{
	int			n;
	struct s_st	*next;
}				t_st;

typedef struct	s_ps //структура с указателями на два стэка
{
	t_st	*stack_a;
	t_st	*stack_b;
}				t_ps;

void			error(void);
void			pa(t_ps *s);
void			pb(t_ps *s);
void			sa(t_ps *s);
void			sb(t_ps *s);
void			ss(t_ps *s);
void			ra(t_ps *s);
void			rb(t_ps *s);
void			rr(t_ps *s);
void			rra(t_ps *s);
void			rrb(t_ps *s);
void			rrr(t_ps *s);
int				main(int argc, char **argv);
void			do_algorithm(t_ps *s);

#endif
