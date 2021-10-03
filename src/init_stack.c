/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:33:18 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/03 21:33:08 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	init_stack(int *arr, int c, t_stack **stack_a)
{
	int		iter_c;
	t_stack *new;

	iter_c = c;
	while (--iter_c > -1)	
	{
		if (c == iter_c)
			*stack_a = ft_newstack(arr[iter_c]);
		else
		{
			new = (t_stack *)malloc(sizeof(t_stack) * 1);	
			if (!new)
				return (0);
			new->number = arr[iter_c];
			ft_stackadd_front(stack_a, new);
		}
	}
	return (1);
}