/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_moves_algorithm_large.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 22:55:51 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/02 21:26:08 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	launch_moves(t_data *data, int tcs, int tcb)
{
	int i;

	i = 0;
	if (tcs < data->initial - tcb)
	{
		i = 1;
		if (tcs == 1)
			pushnode(data->stack_a, data->stack_b, 'b');
		else
		{
			while (i++ < tcs)
				rotatenode(data->stack_a, 'a');
			pushnode(data->stack_a, data->stack_b, 'b');
		}

	}
	else
	{
		if (tcb == data->c)
			rrotatenode(data->stack_a, 'a');
		else
			while (i++ < data->initial - tcb)
				rrotatenode(data->stack_a, 'a');
		pushnode(data->stack_a, data->stack_b, 'b');
	}
	data->c--;
}
