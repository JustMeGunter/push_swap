/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:54:28 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/17 18:54:47 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static int	slct_tree_four(t_stack **stack_a, t_stack **stack_b, int **arr,
		int *tarr, int c)
{
	int	*parr;
	int	*tparr;
	int	tc;
	int	i;

	tparr = (int *)malloc((c - 1) * sizeof(int));
	if (!tparr)
		return (0);
	parr = (int *)malloc((c - 1) * sizeof(int));
	if (!parr)
		return (0);
	if ((*arr)[3] == tarr[0])
	{
		pushnode(stack_a, stack_b, 'b');
		algorithm_three(arr, c - 1, stack_a);
		pushnode(stack_b, stack_a, 'a');
		rotatenode(stack_a, 'a');
	}
	else if ((*arr)[2] == tarr[0])
	{
		swapnode(stack_a, 'a');	
		pushnode(stack_a, stack_b, 'b');
		algorithm_three(arr, c - 1, stack_a);
		pushnode(stack_b, stack_a, 'a');
		rotatenode(stack_a, 'a');
	}
	else if ((*arr)[1] == tarr[0])
	{
		tc = c + 1;
		while (tc-- > 1)
			tparr[tc - 1] = tarr[tc];	
		tc = c;
		i = 0;
		while (tc-- > 0)
			if ((*arr)[tc] != tarr[0])
				parr[i++] = (*arr)[tc];
		rrotatenode(stack_a, 'a');	
		rrotatenode(stack_a, 'a');	
		pushnode(stack_a, stack_b, 'b');
		tc = parr[0];
		parr[0] = parr[2];
		parr[2] = parr[1]; 
		parr[1] = tc;
		if (!reverse_array(&parr, c - 1))
			exit (0);
		algorithm_three(&parr, c - 1, stack_a);
		pushnode(stack_b, stack_a, 'a');
		rotatenode(stack_a, 'a');
	}
	free(parr);
	free(tparr);
	return (1);
}

int	algorithm_four(int **arr, int c, t_stack **stack_a, t_stack **stack_b)
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
	slct_tree_four(stack_a, stack_b, arr, tarr, c);
	free(tarr);
	return (1);
}
