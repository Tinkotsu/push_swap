/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:31:03 by ifran             #+#    #+#             */
/*   Updated: 2019/10/30 23:42:09 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_st
{
	int			n;
	struct s_st	*next;
}				t_st;

typedef struct	s_ps
{
	t_st	*stack_a;
	t_st	*stack_b;
}				t_ps;

//отсортировать функции внизу, некрасиво :(

void			leave_three(t_ps *s);
void			validate_and_push(char *str, t_ps *s);
size_t			stack_len(t_st *stack_a);
int				find_min(t_st *stack);
int				find_max(t_st *stack);
int				is_sorted(t_st *stack);
int				is_r_sorted(t_st *stack);
int				main(int argc, char **argv);
void			error(void); //уточнить про вывод ошибки
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
void			push_swap(t_ps *s);
void 			test(t_ps *s);


#endif
