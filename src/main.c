/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:25:20 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/17 16:38:13 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static int	error_msg(void)
{
	write(1, "Error\n", 6);
	return (1);
}

void	check_leaks(void)
{
	system("leaks push_swap");
}

void	read_stack(t_stack *stack)
{
	while (stack)
	{
		printf("from stack:%i\n", stack->number);
		stack = stack->next;
	}
}

int	reverse_array(int **arr, int c)
{
	int		*tmp_arr;
	t_vloop	vart;

	tmp_arr = (int *)malloc(c * sizeof(int));
	if (!tmp_arr)
		return (0);
	vart.i = c;
	vart.j = 0;
	while (--vart.i > -1)
		tmp_arr[vart.j++] = (*arr)[vart.i];
	while (c-- > 0)
		(*arr)[c] = tmp_arr[c];
	free(tmp_arr);
	return (1);
}

int	no_rn(int *arr, int c)
{
	t_vloop tvar;

	tvar.i = -1;
	tvar.j = -1;
	tvar.k = 0;
	while (++tvar.i < c)
	{
		while (++tvar.j < c)
			if (arr[tvar.i] == arr[tvar.j])
				tvar.k++;
		if (tvar.k > 1)
			return (0);
		tvar.k = 0;
		tvar.j = -1;
	}
	return (1);
}
int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
    int		*arr;
    int		c;

	atexit(check_leaks);
	if (argc < 3)
		error_msg();
    c = 0;
	stack_b = NULL;
    while (argv[++c])
        if (!digit_parser(argv[c]) && error_msg())
            return (0);
    if (!load_initial_values(argv, &arr) && error_msg())
        exit (0);
    c = notnull_values(argv);
	if (!no_rn(arr, c) && error_msg()) 
		exit (0);
	if (reverse_array(&arr, c) && !init_stack(arr, c, &stack_a))
		exit (0);
	if (!select_resolution(arr, c, &stack_a, &stack_b))
		exit (0);
    while (c-- > 0)
        printf("%i e\n", arr[c]);
	read_stack(stack_a);
	ft_stackdel(&stack_a);
	ft_stackdel(&stack_b);
	free(arr);
}
