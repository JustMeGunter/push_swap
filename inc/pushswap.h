/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:28:24 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/03 20:23:20 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <stdio.h>

int	digit_parser(char *str);
int	notnull_values(char **argv);
int	load_initial_values(char **argv, int **arr_num);
int	init_stack(int *arr, int c, t_stack **stack_a);

#endif
