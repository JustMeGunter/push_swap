/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:54:28 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/19 21:06:17 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static int	slct_tree_four(t_data *data)
{
	int	*parr;
	int	*tparr;

	tparr = (int *)malloc((data->c - 1) * sizeof(int));
	if (!tparr)
		exit (0);
	parr = (int *)malloc((data->c - 1) * sizeof(int));
	if (!parr)
		exit (0);
	if (data->arr[3] == data->tarr[0])
		agfour_case_one(data);
	else if (data->arr[2] == data->tarr[0])
		agfour_case_two(data);
	else if (data->arr[1] == data->tarr[0])
		agfour_case_three(data, parr, tparr);
	else if (data->arr[0] == data->tarr[0])
		agfour_case_four(data, parr, tparr);
	free(parr);
	free(tparr);
	return (1);
}

int	algorithm_four(t_data *data)
{
	int	tc;

	data->tarr = (int *)malloc(data->c * sizeof(int));
	if (!data->tarr)
		return (0);
	tc = data->c;
	while (tc-- > 0)
		data->tarr[tc] = data->arr[tc];
	if (!ft_order_array(&data->tarr, data->c))
		return (0);
	slct_tree_four(data);
	free(data->tarr);
	return (1);
}
