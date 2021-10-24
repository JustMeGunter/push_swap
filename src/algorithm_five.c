/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:06:32 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/24 21:27:19 by acrucesp         ###   ########.fr       */
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
	tmp_stack = *data->stack_a;
	tc = -1;
	while (tmp_stack)
	{
		data->arr[++tc] = tmp_stack->number; 
		tmp_stack = tmp_stack->next;
	}
	reverse_array(&data->arr, data->c);
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
	data->tarr = NULL;
	second_step(data);
}

void	algorithm_five(t_data *data)
{
	int	tc;

	data->tarr = (int *)malloc(data->c * sizeof(int));
	if (!data->tarr)
		exit (0);
	tc = data->c;
	while (tc-- > 0)
		data->tarr[tc] = data->arr[tc];
	ft_order_array(&data->tarr, data->c);
	first_step(data);
}
