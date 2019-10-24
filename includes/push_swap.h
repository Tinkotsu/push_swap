/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:31:03 by ifran             #+#    #+#             */
/*   Updated: 2019/10/24 17:37:55 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>

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

#endif
