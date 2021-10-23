/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:28:24 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/23 20:57:27 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <stdio.h>


typedef struct s_stack
{
	int		number;
	void	*next;
}				t_stack;
typedef struct	s_vloop
{
	char	k;
	int		i;
	int		j;
}	t_vloop;
typedef struct	s_data
{
	int		c;
	int		*arr;
	int		*tarr;
	t_stack	**stack_a;
	t_stack	**stack_b;
}	t_data;
typedef struct	s_tmpstacks
{
	t_stack	*tmp_first;
	t_stack	*tmp_last;
	t_stack	*tmp_stack;
}	t_tmpstacks;

void	read_stack(t_stack *stack);
int		digit_parser(char *str);
int		notnull_values(char **argv);
int		load_initial_values(char **argv, int **arr_num);
int		init_stack(int *arr, int c, t_stack **stack_a);
void	swapnode(t_stack **stack, char c);
void	swapnodes(t_stack **stack_a ,t_stack **stack_b);
void	pushnode(t_stack **stack_a, t_stack **stack_b, char c);
void	rotatenode(t_stack **stack, char c);
void	rotatenodes(t_stack **stack_a, t_stack **stack_b);
void	rrotatenode(t_stack **stack, char c);
void	rrotatenodes(t_stack **stack_a, t_stack **stack_b);
int		select_resolution(t_data *data);
int		stackadd_node(t_stack **stack, int number);
int		algorithm_three(int **arr, int c, t_stack **stack_a);
int		ft_order_array(int **arr, int c);
int		algorithm_two(int **arr, int c, t_stack **stack_a);
int		algorithm_four(t_data *data);
int		algorithm_five(t_data *data);
void	read_stack(t_stack *stack);
int		reverse_array(int **arr, int c);
void	agfour_case_one(t_data *data);
void	agfour_case_two(t_data *data, int *parr, int *tparr);
void	agfour_case_three(t_data *data, int *parr, int *tparr);
void	agfour_case_four(t_data *data, int *parr, int *tparr);
void	ft_stackadd_front(t_stack **last, t_stack *new);
t_stack	*ft_newstack(int number);
void	ft_stackdel(t_stack **stack);
void	ft_stackclear(t_stack **stack, void(*del)(int));

#endif
