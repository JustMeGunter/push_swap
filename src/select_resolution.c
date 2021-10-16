/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:00:51 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/16 20:42:36 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	select_resolution(int *arr, int c, t_stack **stack_a, t_stack **stack_b)
{
	if (c == 3)
		if (!algorithm_three(&arr, c, stack_a))
			return (0);
	(void)stack_b;
	return (1);
}
