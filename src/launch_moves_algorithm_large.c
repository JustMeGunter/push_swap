/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_moves_algorithm_large.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 22:55:51 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/04 22:36:13 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>


int		moves_top(t_data *data, int tcs)
{
	int i;
	int ret;

	i = 1;
	if (tcs == 1)
	{
		ret = (*data->stack_a)->number;
		pushnode(data->stack_a, data->stack_b, 'b');
	}
	else
	{
		while (i++ < tcs)
			rotatenode(data->stack_a, 'a');
		ret = (*data->stack_a)->number;
		pushnode(data->stack_a, data->stack_b, 'b');
	}
	return (ret);
}

int		moves_down(t_data *data, int tcb)
{
	int i;
	int	ret;

	i = 0;
	if (tcb == data->c)
		rrotatenode(data->stack_a, 'a');
	else
		while (i++ < data->initial - tcb)
			rrotatenode(data->stack_a, 'a');
	if (data->c - tcb == 1 && tcb != data->c)
		rrotatenode(data->stack_a, 'a');
	ret = (*data->stack_a)->number;
	pushnode(data->stack_a, data->stack_b, 'b');
	return (ret);
}

int		launch_moves(t_data *data, int tcs, int tcb)
{
	int ret;

	if (tcs < data->initial - tcb)
		ret = moves_top(data, tcs);
	else
		ret = moves_down(data, tcb);
	return (ret);
}
