/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:09:36 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/16 20:45:35 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	pushnode(t_stack **stack_a, t_stack **stack_b, char c)
{
	t_stack	*tmp_a;
	t_stack *tmp;
	t_stack *test;

	tmp_a = *stack_a;
	tmp = *stack_a;
	if (!*stack_b)
	{
		*stack_a = tmp->next;
		tmp_a->next = NULL;
		*stack_b = tmp_a;
	}
	else
	{
		test = *stack_b;
		*stack_a = tmp->next;
		tmp_a->next = test;
		*stack_b = tmp_a; 	
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}
