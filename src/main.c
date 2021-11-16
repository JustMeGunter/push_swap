/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:25:20 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/16 19:10:17 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static int	error_msg(void)
{
	write(1, "Error\n", 6);
	return (1);
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
	t_vloop	tvar;

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

	if (argc < 3 && error_msg())
		exit (0);
	data.c = 0;
	stack_b = NULL;
	ft_memset(&data, 0, sizeof(t_data));
	while (argv[++data.c])
		if (!digit_parser(argv[data.c]) && error_msg())
			exit (0);
	if (!load_initial_values(argv, &data.arr) && error_msg())
		exit (0);
	data.c = notnull_values(argv);
	if (!no_rn(data.arr, data.c) && error_msg())
		exit (0);
	if (reverse_array(&data.arr, data.c)
		&& !init_stack(data.arr, data.c, &stack_a))
		exit (0);
	load_data(&data, &stack_a, &stack_b, data.arr);
	select_resolution(&data);
	ft_stackdel(&stack_a);
	ft_stackdel(&stack_b);
	free(data.arr);
}
