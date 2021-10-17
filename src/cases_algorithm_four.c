/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_algorithm_four.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:09:14 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/17 21:23:01 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	agfour_case_one(t_data *data)
{
		pushnode(data->stack_a, data->stack_b, 'b');
		algorithm_three(&data->arr, data->c - 1, data->stack_a);
		pushnode(data->stack_b, data->stack_a, 'a');
		rotatenode(data->stack_a, 'a');
}

void	agfour_case_two(t_data *data)
{
		swapnode(data->stack_a, 'a');	
		pushnode(data->stack_a, data->stack_b, 'b');
		algorithm_three(&data->arr, data->c - 1, data->stack_a);
		pushnode(data->stack_b, data->stack_a, 'a');
		rotatenode(data->stack_a, 'a');
}

void	agfour_case_three(t_data *data)
{

	int	*parr;
	int	*tparr;
	int	tc;
	int	i;

	tparr = (int *)malloc((data->c - 1) * sizeof(int));
	if (!tparr)
		exit (0);
	parr = (int *)malloc((data->c - 1) * sizeof(int));
	if (!parr)
		exit (0);
	tc = data->c + 1;
	while (tc-- > 1)
		tparr[tc - 1] = data->tarr[tc];	
	tc = data->c;
	i = 0;
	while (tc-- > 0)
		if (data->arr[tc] != data->tarr[0])
			parr[i++] = data->arr[tc];
	rrotatenode(data->stack_a, 'a');	
	rrotatenode(data->stack_a, 'a');	
	pushnode(data->stack_a, data->stack_b, 'b');
	tc = parr[0];
	parr[0] = parr[2];
	parr[2] = parr[1]; 
	parr[1] = tc;
	if (!reverse_array(&parr, data->c - 1))
		exit (0);
	algorithm_three(&parr, data->c - 1, data->stack_a);
	pushnode(data->stack_b, data->stack_a, 'a');
	rotatenode(data->stack_a, 'a');
	free(parr);
	free(tparr);
}

void	agfour_case_four(t_data *data)
{
	int	*parr;
	int	*tparr;
	int	tc;
	int	i;

	tparr = (int *)malloc((data->c - 1) * sizeof(int));
	if (!tparr)
		exit (0);
	parr = (int *)malloc((data->c - 1) * sizeof(int));
	if (!parr)
		exit (0);
		tc = data->c + 1;
	while (tc-- > 1)
		tparr[tc - 1] = data->tarr[tc];	
	tc = data->c;
	i = 0;
	while (tc-- > 0)
		if (data->arr[tc] != data->tarr[0])
			parr[i++] = data->arr[tc];
	rrotatenode(data->stack_a, 'a');	
	pushnode(data->stack_a, data->stack_b, 'b');
	if (!reverse_array(&parr, data->c - 1))
		exit (0);
	algorithm_three(&parr, data->c - 1, data->stack_a);
	pushnode(data->stack_b, data->stack_a, 'a');
	rotatenode(data->stack_a, 'a');
	free(parr);
	free(tparr);
}
