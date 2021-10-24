/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:03:33 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/24 18:59:40 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static void	slct_tree_three(t_stack **stack_a, int **arr, int *tarr)
{
	if ((*arr)[2] == tarr[0] && (*arr)[0] == tarr[2])
	{
		swapnode(stack_a, 'a');
		rrotatenode(stack_a, 'a');		
	}
	else if ((*arr)[2] == tarr[1] && (*arr)[0] == tarr[0])
		swapnode(stack_a, 'a');
	else if ((*arr)[2] == tarr[0] && (*arr)[0] == tarr[1])
		rotatenode(stack_a, 'a');
	else if ((*arr)[2] == tarr[2] && (*arr)[0] == tarr[1])
	{
		swapnode(stack_a, 'a');
		rotatenode(stack_a, 'a');		
	}
	else if ((*arr)[2] == tarr[1] && (*arr)[0] == tarr[2])
		rrotatenode(stack_a, 'a');		
}

void	algorithm_three(int **arr, int c, t_stack **stack_a)
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
	slct_tree_three(stack_a, arr, tarr);
	free(tarr);
}
