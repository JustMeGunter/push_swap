/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:09:13 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/16 19:03:45 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackdel(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	if (!stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	*stack = NULL;
}
