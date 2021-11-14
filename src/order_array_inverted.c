/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_array_inverted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:37:23 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/14 21:03:45 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	order_array_inverted(int **arr, int c, t_data *data)
{
	int		*tmp_arr;
	int		*tmp_r_arr;
	t_stack	*tmp_stack;
	int		i;
	int		y;
	int		j;

	i = -1;
	j = c;
	tmp_arr = (int *)malloc(c * sizeof(int));
	if (!tmp_arr)
		exit (0);
	tmp_r_arr = (int *)malloc(c * sizeof(int));
	if (!tmp_r_arr)
		exit (0);
	while (++i < c) 
		tmp_r_arr[--j] = (*arr)[i];	
	tmp_stack = *data->stack_a;
	i = -1;
	while (++i < c)
	{
		y = -1;
		tmp_arr[i] = 0;	
		while (++y < c)
			if (tmp_r_arr[i] > tmp_r_arr[y])
				tmp_arr[i]++;
		tmp_stack->number = tmp_arr[i];
		if (tmp_stack->next)
			tmp_stack = tmp_stack->next;
	}
	free(tmp_r_arr);
	free(*arr);
	*arr = tmp_arr;
}
