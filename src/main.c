/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:25:20 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/24 21:09:25 by acrucesp         ###   ########.fr       */
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
		exit (0);
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

void	load_data(t_data *data, t_stack **stack_a, t_stack **stack_b,
	   	int *arr)
{
	data->stack_a = stack_a;
	data->stack_b = stack_b;
	data->arr = arr;

}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;
    int		*arr;

	atexit(check_leaks);
	if (argc < 3)
		error_msg();
    data.c = 0;
	stack_b = NULL;
	ft_memset(&data, 0, sizeof(t_data));
    while (argv[++data.c])
        if (!digit_parser(argv[data.c]) && error_msg())
            return (0);
    if (!load_initial_values(argv, &arr) && error_msg())
        exit (0);
    data.c = notnull_values(argv);
	if (!no_rn(arr, data.c) && error_msg()) 
		exit (0);
	if (reverse_array(&arr, data.c) && !init_stack(arr, data.c, &stack_a))
		exit (0);
	load_data(&data, &stack_a, &stack_b, arr);
	select_resolution(&data);
	read_stack(stack_a);
	ft_stackdel(&stack_a);
	ft_stackdel(&stack_b);
	free(arr);
}
/*
* Big than five:
* -its is dived into chunks according to an appropiation
* -start from smallest to largest chunk
* -and swap into stack b if higher its bigger in the top of the steack or rotate if its 
* bigger than the smaller in stack b for the first chunk. For the others only swap.
 */
