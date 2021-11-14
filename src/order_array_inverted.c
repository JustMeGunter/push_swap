/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_array_inverted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:37:23 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/14 19:45:38 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	order_array_inverted(int **arr, int c, t_data *data)
{
	int		*tmp_arr;
	t_stack	*tmp_stack;
	int		i;
	int		y;

	i = -1;
	tmp_arr = (int *)malloc(c * sizeof(int));
	if (!tmp_arr)
		exit (0);
	tmp_stack = *data->stack_a;
	while (++i < c)
	{
		y = -1;
		tmp_arr[i] = 0;	
		while (++y < c)
			if ((*arr)[i] > (*arr)[y])
				tmp_arr[i]++;
		tmp_stack->number = tmp_arr[i];
		if (tmp_stack->next)
			tmp_stack = tmp_stack->next;
	}
	free(*arr);
	*arr = tmp_arr;
}
