/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:43:16 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/17 16:44:32 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	ft_order_array(int **arr, int c)
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
