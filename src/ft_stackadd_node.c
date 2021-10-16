/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:52:26 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/16 17:17:38 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	stackadd_node(t_stack **stack, int number)
{
	t_stack	*new_node;
	char	q;

	if (!*stack)
	{
		*stack = ft_newstack(number);
		if (!*stack)
			return (0);
		return (1);
	}	
	new_node = (t_stack *)ft_calloc(sizeof(*new_node), 1);
	if (!new_node)
		return (0);
	q = 0;
	while (*stack && !q)
	{
		if (!(*stack)->next)	
		{
			(*stack)->next = new_node;
			new_node->number = number;
			new_node->next = NULL;
			q = 1;
		}
		else
			*stack = (*stack)->next;
	}
	return (1);
}
