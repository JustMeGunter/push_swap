/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:03:33 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/16 21:20:46 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	order_array(int **arr, int c)
{
	int		*tmp_arr;
	t_vloop vart;
	int		iter_c;

	iter_c = c;
	vart.i = c;
	vart.j = 0;
	tmp_arr = (int *)malloc(c * sizeof(int));
	if (!tmp_arr)
		return (0);
	while (--iter_c > -1)
	{
		while (--vart.i > -1)
			if ((*arr)[iter_c] < (*arr)[vart.i])
				vart.j++;
		tmp_arr[vart.j] = (*arr)[iter_c];
		vart.i = c;
		vart.j = 0;
	}
    while (c-- > 0)
		(*arr)[c] = tmp_arr[c];
	free(tmp_arr);
	return (1);
}

int	algorithm_three(int **arr, int c, t_stack **stack_a)
{
	int	*tarr;
	int	tc;

	tarr = (int *)malloc(c * sizeof(int));
	if (!tarr)
		return (0);
	tc = c;
	while (tc-- > 0)
		tarr[tc] = (*arr)[tc];
	if (!order_array(&tarr, c))
		return (0);
	if ((*arr)[2] == tarr[0] && (*arr)[0] == tarr[2])
	{
		swapnode(stack_a, 'a');
		rrotatenode(stack_a, 'a');		
	}
	free(tarr);
	return (1);
}
