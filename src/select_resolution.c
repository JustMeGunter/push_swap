/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:00:51 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/21 20:18:23 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	select_resolution(t_data *data)
{
	if (data->c == 2)
	{
		if (!algorithm_two(&data->arr, data->c, data->stack_a))
			return (0);
	}
	else if (data->c == 3)
	{
		if (!algorithm_three(&data->arr, data->c, data->stack_a))
			return (0);
	}
	else if (data->c == 4)
	{
		if (!algorithm_four(data))
			return (0);
	}
	else if (data->c == 5)
	{
		if (!algorithm_five(data))
			return (0);
	}
	else if (data->c > 5)
	{
			return (0);
	}
	return (1);
}
