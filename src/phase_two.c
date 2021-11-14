/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:40:20 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/14 17:31:03 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	phase_two(t_data *data, int size)
{
	int	*tmp_arr;
	int	tmp;
	t_vloop	vloop;

	data->n_chunks = data->in_chunks;
	tmp_arr = (int *)malloc(sizeof(int) * size);
	if (!tmp_arr)
		exit(0);
	tmp = data->initial;
	vloop.y = size / 2;
	vloop.j = size;
	//printf("pivote %i\n", data->tarr[vloop.y]);
	while (vloop.j--)
	{
		if ((*data->stack_b)->number < data->tarr[vloop.y])
		{
			rotatenode(data->stack_b, 'b');
		}
		if ((*data->stack_b)->number >= data->tarr[vloop.y])
		{
			vloop.k = -1;
			vloop.i = 0;
			while (++vloop.k < size)
			{
				if ((*data->stack_b)->number == data->tarr[vloop.k])
					vloop.k = size;
				else
					vloop.i++;
			}
			//getchar();
			pushnode(data->stack_b, data->stack_a, 'a');
		//	if (*data->stack_a && (*data->stack_a)->number != data->tarr[0] 
		//		&& (*data->stack_a)->number == data->tarr[vloop.i - 1]) 
		//		swapnode(data->stack_a, 'a');
		//	else if (
		}
	}

	free(tmp_arr);
}
