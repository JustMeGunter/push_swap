/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:08:30 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/09 18:36:28 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	swapnode(t_stack **stack)
{
	t_stack *tmp_first;
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
}
