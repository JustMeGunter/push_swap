/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotatenode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:46:11 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/15 20:55:33 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	rrotatenodes(t_stack **stack_a, t_stack **stack_b)
{
	rrotatenode(stack_a, 'x');
	rrotatenode(stack_b, 'x');
	write(1, "rrr\n", 4);
}

void	draw_rrotate(char c)
{
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrotatenode(t_stack **stack, char c)
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
		(*stack) = tmp.tmp_last;
		(*stack)->next = tmp.tmp_first;
		tmp.tmp_stack->next = NULL;
	}
	else
		swapnode(stack, 'x');
	draw_rrotate(c);
}
