//HEADER

#ifndef CHECKER_H

# define CHECKER_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_st
{
	int			n;
	struct s_nb	*next;
}				t_st;

typedef struct	s_ps
{
	t_st	*stack_a;
	t_st	*stack_b;
}				t_ps;


void			checker(t_ps *s);
int				main(int argc, char **argv);
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

#endif
