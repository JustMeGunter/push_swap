/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:21:40 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/14 20:17:22 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		sort_stack(t_data *data)
{
	t_stack	*tmp_stack;
	t_stack	*new_stack;

	tmp_stack = *data->stack_a;
	while(tmp_stack->next)
	{
		new_stack = tmp_stack->next;
		if (tmp_stack->number > new_stack->number)
			return (1);
		tmp_stack = tmp_stack->next;
	}
	return (0);
}

void	algorithm_large(t_data *data)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	order_array_inverted(&data->arr, data->c, data);
	while (sort_stack(data))
	{
		while (i < data->c)
		{
			if ((*data->stack_a)->number & (1 << j)) 
				rotatenode(data->stack_a, 'a');
			else 
				pushnode(data->stack_a, data->stack_b, 'b');
			i++;
		}
		while (*data->stack_b)
			pushnode(data->stack_b, data->stack_a, 'a');
		j++;
		i = 0;
	}
}
