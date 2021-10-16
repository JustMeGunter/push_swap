/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotatenode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:23:30 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/16 20:57:57 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	rotatenodes(t_stack **stack_a, t_stack **stack_b)
{
	rotatenode(stack_a, 'x');
	rotatenode(stack_b, 'x');
	write(1, "rr\n", 3);
}

void draw_rotate(char c)
{
	if (c == 'a')
		write(1, "ra\n", 2);
	else if (c == 'b')
		write(1, "rb\n", 2);
}

void	rotatenode(t_stack **stack, char c)
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
		swapnode(stack, 'x');
	draw_rotate(c);
}
