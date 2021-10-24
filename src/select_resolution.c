/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:00:51 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/24 19:08:03 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	select_resolution(t_data *data)
{
	if (data->c == 2)
		algorithm_two(&data->arr, data->c, data->stack_a);
	else if (data->c == 3)
		algorithm_three(&data->arr, data->c, data->stack_a);
	else if (data->c == 4)
		algorithm_four(data);
	else if (data->c == 5)
		algorithm_five(data);
	else if (data->c > 5)
	{
			return (0);
	}
	return (1);
}
