/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:33:18 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/19 20:38:30 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	init_stack(int *arr, int c, t_stack **stack_a)
{
	int		iter_c;
	t_stack *new;

	iter_c = -1;
	while (++iter_c < c)	
	{
		new = (t_stack *)malloc(sizeof(t_stack) * 1);	
		if (!new)
			return (0);
		new->number = arr[iter_c];
		ft_stackadd_front(stack_a, new);
	}
	return (1);
}
