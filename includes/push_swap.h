/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:31:03 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 18:44:17 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "common.h"

int				main(int argc, char **argv);
void			push_swap(t_ps *s);
void			all_free(t_ps *s);
void			do_op(t_ps *s, size_t i);
void			find_ops(t_ps *s, size_t index);
void			do_index(t_ps *s);
void			leave_three(t_ps *s);
void			validate_and_push(char *str, t_ps *s);
size_t			stack_len(t_st *stack);
int				find_min(t_st *stack);
int				find_max(t_st *stack);

#endif
