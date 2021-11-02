/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_moves_algorithm_large.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 22:36:17 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/02 20:54:48 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	return_smaller(int *arr, int size)
{
	int	i;
	int	j;
	int	tcs;

	i = -1;
	j = -1;
	while (++i < size)
	{
		while (++j < size)
			if (arr[i] > arr[j])
				j = size + 1;
		if (j == size && arr[i] > 0)
			tcs = arr[i];
		j = -1;	
	}
	return (tcs);
}

int	return_bigger(int *arr, int size)
{
	int	i;
	int	k;
	int	tcb;

	i = -1;
	k = -1;
	while (++i < size)
	{
		while (++k < size)
			if (arr[i] < arr[k])
				k = size + 1;
		if (k == size)
			tcb = arr[i];
		k = -1;	
	}
	return (tcb);
}

