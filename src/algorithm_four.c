/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:54:28 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/23 19:07:36 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static int	slct_tree_four(t_data *data)
{
	int	*tmparr;
	int	*o_tmparr;

	o_tmparr = (int *)malloc((data->c - 1) * sizeof(int));
	if (!o_tmparr)
		exit (0);
	tmparr = (int *)malloc((data->c - 1) * sizeof(int));
	if (!tmparr)
		exit (0);
	if (data->arr[3] == data->tarr[0])
		agfour_case_one(data);
	else if (data->arr[2] == data->tarr[0])
		agfour_case_two(data, tmparr, o_tmparr);
	else if (data->arr[1] == data->tarr[0])
		agfour_case_three(data, tmparr, o_tmparr);
	else if (data->arr[0] == data->tarr[0])
		agfour_case_four(data, tmparr, o_tmparr);
	free(tmparr);
	free(o_tmparr);
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
