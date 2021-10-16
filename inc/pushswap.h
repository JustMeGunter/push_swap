/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:28:24 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/16 20:43:54 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <stdio.h>

typedef struct	s_vloop
{
	char	k;
	int		i;
	int		j;
}	t_vloop;
typedef struct	s_tmpstacks
{
	t_stack	*tmp_first;
	t_stack	*tmp_last;
	t_stack	*tmp_stack;
}	t_tmpstacks;
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
int		select_resolution(int *arr, int c, t_stack **stack_a, t_stack **stack_b);
int		stackadd_node(t_stack **stack, int number);
int		algorithm_three(int **arr, int c, t_stack **stack_a);

#endif
