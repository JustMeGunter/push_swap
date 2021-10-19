/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:41:29 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/19 20:46:14 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	algorithm_two(int **arr, int c, t_stack **stack_a)
{
	int	*tarr;
	int	tc;

	tarr = (int *)malloc(c * sizeof(int));
	if (!tarr)
		return (0);
	tc = c;
	while (tc-- > 0)
		tarr[tc] = (*arr)[tc];
	if (!ft_order_array(&tarr, c))
		return (0);
	if ((*arr)[1] == tarr[0])	
		swapnode(stack_a, 'a');
	free(tarr);
	return (1);
}
