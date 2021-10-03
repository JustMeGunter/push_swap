/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:25:20 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/03 21:33:18 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static int	error_msg(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
    int		*arr;
    int		c;

	if (argc < 3)
		error_msg();
    c = 0;
    while (argv[++c])
        if (!digit_parser(argv[c]) && error_msg())
            return (0);
    if (!load_initial_values(argv, &arr) && error_msg())
        return(0);
    c = notnull_values(argv);
	if (!init_stack(arr, c, &stack_a))
		return (0);	
    while (c-- > 0)
        printf("%i e\n", arr[c]);
	while (stack_a)
	{
		printf("from stack:%i\n", stack_a->number);
		stack_a = stack_a->next;
	}
	free(arr);
}
