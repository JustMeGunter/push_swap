/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:21:40 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/13 16:44:45 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static int	num_chunks(int c)
{
	int		result;
	float	div;

	div = 2;
	result = 0;
	while (result > (0.2 * c) || result == 0)
		result = c / div++;
	return (div - 1);
}

static void	load_moves(t_data *data, int size, int **tmp_arr)
{
	t_stack	*tmp_stack;
	t_vloop vloop;	
	int		tmp;
	
	if (data->in_chunks != data->n_chunks)
	{
		tmp = data->initial - size * (data->in_chunks - data->n_chunks);
		vloop.i = data->initial - (size * (data->in_chunks - data->n_chunks + 1)) - 1;
	}
	else
	{
		tmp = data->initial;
		vloop.i = data->initial - size - 1;
	}
	vloop.j = 0;
	while (++vloop.i < tmp)
	{
		tmp_stack = *data->stack_a;
		vloop.k = 1;
		while (tmp_stack)
		{
			vloop.y = tmp_stack->number;
			if (data->c_chunk)
				iter_chunk(data, tmp_arr, &vloop);	
			else
			{
				if	(tmp_stack->number == data->tarr[vloop.i])
				{
					(*tmp_arr)[vloop.j++] = vloop.k;	
					printf("chunk: %i, moves: %i\n", data->tarr[vloop.i], vloop.k);
				}
			}
			tmp_stack = tmp_stack->next;
			vloop.k++;
		}
	}
}


static void	execute_moves(t_data *data, int size, int **tmp_arr)
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
		tcs = return_smaller(*tmp_arr, i);
		tcb = return_bigger(*tmp_arr, i);
		if (*data->stack_a)
			num = launch_moves(data, tcs, tcb);
		printf("---->%i\n", num);
		data->c_chunk[j++] = num;
		printf("----x%i\n", data->c_chunk[j - 1]);
		load_moves(data, size, tmp_arr);
	}
	free(data->c_chunk);
	//phase 2 while data->tarr getting the bigger for push to stack_a while into stack b
	//when search for the biggest in the stack_b calculate n_moves to know if need to rrb or rb
}

static void	select_min_num_move(t_data *data, int size)
{
	int *tmp_arr;

	tmp_arr = (int *)malloc(size * sizeof(int));
	if (!tmp_arr)
		exit (0);
	while (data->n_chunks)
	{	
		load_moves(data, size, &tmp_arr);
		execute_moves(data, size, &tmp_arr);
		data->n_chunks--;
	}
	free(tmp_arr);
}

void	algorithm_large(t_data *data)
{
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
	data->n_chunks = num_chunks(data->c + 1); 
	tc = data->n_chunks;
	if ((data->c) - (data->n_chunks * ((data->c) / data->n_chunks)) != 0)
		data->n_chunks = data->n_chunks + 1;
	data->in_chunks = data->n_chunks;
	size = (data->c + 1) / tc;
	printf("\nsize:%i, num:%i, data->c: %i\n", size, data->n_chunks, data->c);
	select_min_num_move(data, size);
	free(data->tarr);
}
