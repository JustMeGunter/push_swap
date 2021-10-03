/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 21:35:06 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/03 21:54:32 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackclear(t_stack **stack, void (*del)(int))
{
	t_stack	*last;

	if (!stack)
		return ;
	while (*stack)
	{
		last = (*stack)->next;
		ft_delstack(*stack, del);
		*stack = last;
	}
}
