/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:21:40 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/07 20:03:09 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		num_chunks(int c)
{
	int		result;
	float	div;

	div = 2;
	result = 0;
	while (result > (0.2 * c) || result == 0)
		result = c / div++;
	return (div - 1);
}

void	load_moves(t_data *data, int size, int nn, int **tmp_arr)
{
	t_stack	*tmp_stack;
	t_vloop vloop;	
	
	vloop.i = data->initial - size - 1;
	vloop.j = 0;
	while (++vloop.i < data->initial)
	{
		tmp_stack = *data->stack_a;
		vloop.k = 1;
		while (tmp_stack)
		{
			vloop.y = tmp_stack->number;
			if (data->c_chunk)
				iter_chunk(data, nn, tmp_arr, &vloop);	
			else
				if	(tmp_stack->number == data->tarr[vloop.i])
					(*tmp_arr)[vloop.j++] = vloop.k;	
			tmp_stack = tmp_stack->next;
			vloop.k++;
		}
	}
}


void	execute_move(t_data *data, int size, int **tmp_arr)
{
	int	tcb;
	int	tcs;
	int	i;
	int	j;
	int num;

	i = size;
	j = 0;
	data->c_chunk = (int *)malloc(sizeof(int) * size);	
	if (!data->c_chunk)
		exit (0);
	while (i--)
	{
		tcs = return_smaller(*tmp_arr, size, data);
		tcb = return_bigger(*tmp_arr, size, data);
		num = launch_moves(data, tcs, tcb);
		printf("---->%i\n", num);
		data->c_chunk[j++] = num;
		printf("----x%i\n", data->c_chunk[j - 1]);
		load_moves(data, size, j, tmp_arr);
	}
	free(data->c_chunk);
}

void	select_min_num_move(t_data *data, int size, int n_chunks)
{
	int *tmp_arr;

	tmp_arr = (int *)malloc(size * sizeof(int));
	if (!tmp_arr)
		exit (0);
	//while (n_chunks)
	{	
		load_moves(data, size, n_chunks, &tmp_arr);
		execute_move(data, size, &tmp_arr);
	//	n_chunks--;
	}
	free(tmp_arr);
}

void	algorithm_large(t_data *data)
{
	int		n_chunks;
	int		size;
	int		tc;

	data->tarr = (int *)malloc(data->c * sizeof(int));
	if (!data->tarr)
		exit (0);
	tc = data->c;
	data->initial = data->c;
	while (tc-- > 0)
		data->tarr[tc] = data->arr[tc];
	ft_order_array(&data->tarr, data->c);
	n_chunks = num_chunks(data->c + 1); 
	tc = n_chunks;
	if ((data->c + 1) - (n_chunks * ((data->c + 1) / n_chunks)) != 0)
		n_chunks = n_chunks + 1;
	size = (data->c + 1) / tc;
	printf("\nsize:%i, num:%i, data->c: %i\n", size, n_chunks, data->c);
	select_min_num_move(data, size, n_chunks);
	free(data->tarr);
}
