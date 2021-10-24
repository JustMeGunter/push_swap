/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:06:32 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/24 17:36:10 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static void second_step(t_data *data)
{
	t_stack	*tmp_stack;
	int		tc;
	int		i;

	tc = data->c;
	i = 0;
	data->c = 4;
	data->arr = (int *)malloc((data->c) * sizeof(int));
	if (!data->arr)
		exit (0);
	data->tarr = NULL;
	tmp_stack = *data->stack_a;
	tc = -1;
	while (tmp_stack)
	{
		data->arr[++tc] = tmp_stack->number; 
		tmp_stack = tmp_stack->next;
	}
	if (!reverse_array(&data->arr, data->c))
		exit (0);
	algorithm_four(data);
	pushnode(data->stack_b, data->stack_a, 'a');
	rotatenode(data->stack_a, 'a');
}

static void	first_step(t_data *data)
{
	t_stack	*tmp_stack;
	int		i;
	int		j;

	i = 0; 
	j = 0; 
	tmp_stack = *data->stack_a;
	while (!j && tmp_stack)
	{
		if (data->tarr[0] == tmp_stack->number)
			j = 1;
		tmp_stack = tmp_stack->next;
		i++;
	}
	if (i < 4)
		while (i-- > 1)
			rotatenode(data->stack_a, 'a');
	else
		while (i++ <= 5)
			rrotatenode(data->stack_a, 'a');
	pushnode(data->stack_a, data->stack_b, 'b');
	free(data->arr);
	free(data->tarr);
	second_step(data);
}

int	algorithm_five(t_data *data)
{
	int	tc;

	data->tarr = (int *)malloc(data->c * sizeof(int));
	if (!data->tarr)
		return (0);
	tc = data->c;
	while (tc-- > 0)
		data->tarr[tc] = data->arr[tc];
	if (!ft_order_array(&data->tarr, data->c))
		return (0);
	first_step(data);
	return (1);
}
