/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_algorithm_four.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:09:14 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/15 19:38:15 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	agfour_case_one(t_data *data, int *tmparr)
{
	int	tc;
	int	i;

	tc = data->c;
	i = 0;
	while (tc-- > 0)
		if (data->arr[tc] != data->tarr[3])
			tmparr[i++] = data->arr[tc];
	reverse_array(&tmparr, data->c - 1);
	pushnode(data->stack_a, data->stack_b, 'b');
	algorithm_three(&tmparr, data->c - 1, data->stack_a);
	pushnode(data->stack_b, data->stack_a, 'a');
}

void	agfour_case_two(t_data *data, int *tmparr)
{
	int	tc;
	int	i;

	tc = data->c;
	i = 0;
	while (tc-- > 0)
		if (data->arr[tc] != data->tarr[3])
			tmparr[i++] = data->arr[tc];
	reverse_array(&tmparr, data->c - 1);
	swapnode(data->stack_a, 'a');
	pushnode(data->stack_a, data->stack_b, 'b');
	algorithm_three(&tmparr, data->c - 1, data->stack_a);
	pushnode(data->stack_b, data->stack_a, 'a');
}

void	agfour_case_three(t_data *data, int *tmparr)
{
	int	tc;
	int	i;

	tc = data->c;
	i = 0;
	while (tc-- > 0)
		if (data->arr[tc] != data->tarr[3])
			tmparr[i++] = data->arr[tc];
	rrotatenode(data->stack_a, 'a');
	rrotatenode(data->stack_a, 'a');
	pushnode(data->stack_a, data->stack_b, 'b');
	tc = tmparr[0];
	tmparr[0] = tmparr[2];
	tmparr[2] = tmparr[1];
	tmparr[1] = tc;
	reverse_array(&tmparr, data->c - 1);
	algorithm_three(&tmparr, data->c - 1, data->stack_a);
	pushnode(data->stack_b, data->stack_a, 'a');
}

void	agfour_case_four(t_data *data, int *tmparr)
{
	int	tc;
	int	i;

	tc = data->c;
	i = 0;
	while (tc-- > 0)
		if (data->arr[tc] != data->tarr[3])
			tmparr[i++] = data->arr[tc];
	rrotatenode(data->stack_a, 'a');
	pushnode(data->stack_a, data->stack_b, 'b');
	reverse_array(&tmparr, data->c - 1);
	algorithm_three(&tmparr, data->c - 1, data->stack_a);
	pushnode(data->stack_b, data->stack_a, 'a');
}
