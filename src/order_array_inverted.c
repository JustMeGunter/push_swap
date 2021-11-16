/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_array_inverted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:37:23 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/16 18:45:56 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	reserve_arrays(int c, int **tmp_arr, int **tmp_r_arr, int **arr)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = c;
	*tmp_arr = (int *)malloc(c * sizeof(int));
	if (!tmp_arr)
		exit (0);
	*tmp_r_arr = (int *)malloc(c * sizeof(int));
	if (!tmp_r_arr)
		exit (0);
	while (++i < tmp)
		(*tmp_r_arr)[--c] = (*arr)[i];
}

void	order_array_inverted(int **arr, int c, t_data *data)
{
	int		*tmp_arr;
	int		*tmp_r_arr;
	t_stack	*tmp_stack;
	t_vloop	vloop;

	vloop.j = c;
	reserve_arrays(c, &tmp_arr, &tmp_r_arr, arr);
	tmp_stack = *data->stack_a;
	vloop.i = -1;
	while (++vloop.i < c)
	{
		vloop.y = -1;
		tmp_arr[vloop.i] = 0;
		while (++vloop.y < c)
			if (tmp_r_arr[vloop.i] > tmp_r_arr[vloop.y])
				tmp_arr[vloop.i]++;
		tmp_stack->number = tmp_arr[vloop.i];
		if (tmp_stack->next)
			tmp_stack = tmp_stack->next;
	}
	free(tmp_r_arr);
	free(*arr);
	*arr = tmp_arr;
}
