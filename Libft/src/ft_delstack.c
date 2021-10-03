/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 21:39:05 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/03 21:49:26 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delstack(t_stack *stack, void (*del)(int))
{
	if (!stack)
		return ;
	if (del)
		del(stack->number);
	free(stack);
}
