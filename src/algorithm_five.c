/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:06:32 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/21 21:34:01 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static int	slct_tree_five(t_data *data)
{
	int		*parr;
	int		tc;
	t_stack	*tmp_stack;
	int		i;
	int		j;

	parr = (int *)malloc((data->c - 1) * sizeof(int));
	if (!parr)
		exit (0);
	i = 0; 
	j = 0; 
	tmp_stack = *data->stack_a;
	printf("i: %i\n", data->tarr[4]); 
	while (!j &&tmp_stack)
	{
		if (data->tarr[4] == tmp_stack->number)
			j = 1;
		tmp_stack = tmp_stack->next;
		i++;
	}
	if (i < 4)
	{
		while (i-- > 1)
			rotatenode(data->stack_a, 'a');
	}
	else
	{
		while (i++ <= 5)
			rrotatenode(data->stack_a, 'a');
	}
	pushnode(data->stack_a, data->stack_b, 'b');
	tc = data->c;
	i = 0;
	while (tc-- > 0)
		if (data->arr[tc] != data->tarr[4])
			parr[i++] = data->arr[tc];
	data->c = 4;
	free(data->arr);
	free(data->tarr);
	data->arr = (int *)malloc((data->c) * sizeof(int));
	if (!data->arr)
		exit (0);
	data->tarr = NULL;
	while (++tc < 4)
		data->arr[tc] = parr[tc];	
	free(parr);
	algorithm_four(data);
	pushnode(data->stack_b, data->stack_a, 'a');
	//printf("a\n"); 
	//read_stack(*data->stack_a);
	//printf("b\n"); 
	//read_stack(*data->stack_b);
	return (1);
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
	slct_tree_five(data);
	return (1);
}
