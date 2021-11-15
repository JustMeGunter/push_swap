/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:08:30 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/15 20:56:14 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	swapnodes(t_stack **stack_a, t_stack **stack_b)
{
	swapnode(stack_a, 'x');
	swapnode(stack_b, 'x');
	write(1, "ss\n", 3);
}

void	swapnode(t_stack **stack, char c)
{
	t_stack	*tmp_first;
	t_stack	*tmp_second;
	t_stack	*tmp;

	tmp_first = *stack;
	if (!tmp_first->next)
		return ;
	tmp_second = tmp_first->next;
	tmp = tmp_second->next;
	tmp_second->next = tmp_first;
	tmp_first->next = tmp;
	*stack = tmp_second;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}
