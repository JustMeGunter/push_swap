/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:09:36 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/09 20:48:10 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

// get node enved a number
void	pushnode(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	//t_stack	*tmp_b;
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
	// change node from top stack_a for first in stack_b and put second node if exists from stack_a as first
}
