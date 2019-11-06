//HEADER

#include "checker.h"

int		main(int argc, char **argv)
{
	int		i;
	t_ps	*s;

	if (argc <= 1)
		return (0);
	i = 1;
	if (!(s = (t_ps *)malloc(sizeof(t_ps))))
		error();
	s->stack_a = NULL;
	s->stack_b = NULL;
	while (argv[i])
	{
		validate_and_push(argv[i], s);
		++i;
	}
	checker(s);
	return (0);
}
