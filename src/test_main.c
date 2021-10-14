/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:25:20 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/14 18:45:45 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static int	error_msg(void)
{
	write(1, "Error\n", 6);
	return (1);
}

void	check_leaks(void)
{
	system("leaks push_swap");
}

void	read_stack(t_stack *stack)
{
	while (stack)
	{
		printf("from stack:%i\n", stack->number);
		stack = stack->next;
	}
}

int	stackadd_node(t_stack **stack, int number)
{
	//t_stack	*tmp;
	t_stack	*new_node;
	char	q;

	if (!*stack)
	{
		*stack = ft_newstack(number);
		if (!*stack)
			return (0);
		return (1);
	}	
	new_node = (t_stack *)ft_calloc(sizeof(*new_node), 1);
	if (!new_node)
		return (0);
	q = 0;
	while (*stack && !q)
	{
		if (!(*stack)->next)	
		{
			(*stack)->next = new_node;
			new_node->number = number;
			new_node->next = NULL;
			q = 1;
		}
		else
			*stack = (*stack)->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
    int		*arr;
    int		c;

	atexit(check_leaks);
	if (argc < 3)
		error_msg();
    c = 0;
	stack_b = NULL;
    while (argv[++c])
        if (!digit_parser(argv[c]) && error_msg())
            return (0);
    if (!load_initial_values(argv, &arr) && error_msg())
        return(0);
    c = notnull_values(argv);
	if (!init_stack(arr, c, &stack_a))
		return (0);	
    while (c-- > 0)
        printf("%i e\n", arr[c]);
	read_stack(stack_a);
	swapnode(&stack_a);
	read_stack(stack_a);
	stackadd_node(&stack_b, 8);
	pushnode(&stack_a, &stack_b);
	write(1, "a\n", 2);
	read_stack(stack_a);
	write(1, "b\n", 2);
	read_stack(stack_b);
	pushnode(&stack_b, &stack_a);
	write(1, "b\n", 2);
	read_stack(stack_b);
	write(1, "sb\n", 3);
	read_stack(stack_b);
	write(1, "\n", 1);
	stackadd_node(&stack_b, 7);
	write(1, "a\n", 2);
	read_stack(stack_a);
	write(1, "b\n", 2);
	read_stack(stack_b);
	swapnodes(&stack_a, &stack_b);
	write(1, "sa\n", 3);
	read_stack(stack_a);
	write(1, "sb\n", 3);
	read_stack(stack_b);
	rotatenode(&stack_a);
	write(1, "ra\n", 3);
	read_stack(stack_a);
	rotatenodes(&stack_a, &stack_b);
	write(1, "a\n", 2);
	read_stack(stack_a);
	write(1, "b\n", 2);
	read_stack(stack_b);
	rrotatenode(&stack_a);
	write(1, "ra\n", 3);
	read_stack(stack_a);
	ft_stackdel(&stack_a);
	ft_stackdel(&stack_b);
	free(arr);
}
