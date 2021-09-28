#include "libft.h"

t_stack *ft_newstack(int number)
{
	t_stack *elmt;

	elmt = (t_stack *)ft_calloc(sizeof(*elmt), 1);
	if (!elmt)
		return (0);
	elmt->number = number;
	return (elmt);
}
