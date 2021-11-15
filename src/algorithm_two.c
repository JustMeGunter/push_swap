/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:41:29 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/15 19:57:56 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	algorithm_two(int **arr, int c, t_stack **stack_a)
{
	int	*tarr;
	int	tc;

	tarr = (int *)malloc(c * sizeof(int));
	if (!tarr)
		exit (0);
	tc = c;
	while (tc-- > 0)
		tarr[tc] = (*arr)[tc];
	ft_order_array(&tarr, c);
	if ((*arr)[1] == tarr[0])
		swapnode(stack_a, 'a');
	free(tarr);
}
