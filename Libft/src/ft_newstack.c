/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:59:08 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/09 19:01:57 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_stack	*ft_newstack(int number)
{
	t_stack	*elmt;

	elmt = (t_stack *)ft_calloc(sizeof(*elmt), 1);
	if (!elmt)
		return (0);
	elmt->number = number;
	elmt->next = NULL;
	return (elmt);
}
