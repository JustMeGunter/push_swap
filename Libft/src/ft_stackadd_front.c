/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:45:07 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/03 19:45:29 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackadd_front(t_stack **last, t_stack *new)
{
	if (!last || !new)
		return ;
	if (!*last)
	{
		new->next = 0;
		*last = new;
	}
	else
	{
		new->next = *last;
		*last = new;
	}
}
