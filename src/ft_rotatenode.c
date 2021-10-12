/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotatenode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:23:30 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/12 20:45:41 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	rotatenodes(t_stack **stack_a, t_stack **stack_b)
{
	rotatenode(stack_a);
	rotatenode(stack_b);
}

void	rotatenode(t_stack **stack)
{
	t_tmpstacks	tmp;
	t_vloop		vars;

	tmp.tmp_stack = *stack;
	tmp.tmp_first = *stack;
	ft_bzero(&vars, sizeof(vars));
	while (tmp.tmp_stack && !vars.k)
	{
		tmp.tmp_last = tmp.tmp_stack->next;
		if (tmp.tmp_last->next)
			tmp.tmp_stack = tmp.tmp_stack->next;	
		else
			vars.k = 1;
		vars.i++;
	}
	if (vars.i > 1)
	{
		(*stack) = tmp.tmp_first->next;
		tmp.tmp_last->next = tmp.tmp_first;
		tmp.tmp_first->next = NULL;
	}
	else
		swapnode(stack);
}
