/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:14:26 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/19 20:33:30 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h> 

void	ft_stackdel(t_stack **stack)
{
	t_stack	*tmp;
	t_stack *tmp_next;

	if (!stack)
		return ;
	tmp = *stack;
	while(tmp)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	*stack = NULL;
}
