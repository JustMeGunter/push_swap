/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:54:28 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/24 19:09:22 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static void	slct_tree_four(t_data *data)
{
	int	*tmparr;

	tmparr = (int *)malloc((data->c - 1) * sizeof(int));
	if (!tmparr)
		exit (0);
	if (data->arr[3] == data->tarr[3])
		agfour_case_one(data, tmparr);
	else if (data->arr[2] == data->tarr[3])
		agfour_case_two(data, tmparr);
	else if (data->arr[1] == data->tarr[3])
		agfour_case_three(data, tmparr);
	else if (data->arr[0] == data->tarr[3])
		agfour_case_four(data, tmparr);
	free(tmparr);
}

void	algorithm_four(t_data *data)
{
	int	tc;

	data->tarr = (int *)malloc(data->c * sizeof(int));
	if (!data->tarr)
		exit (0);
	tc = data->c;
	while (tc-- > 0)
		data->tarr[tc] = data->arr[tc];
	ft_order_array(&data->tarr, data->c);
	slct_tree_four(data);
	free(data->tarr);
}
