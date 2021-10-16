/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:07:28 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/16 18:06:51 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int digit_parser(char *str)
{
	t_vloop	tvar;

    tvar.i = -1;
    tvar.k = 0;
    if (!str[0])
        return (0);
    while (str[++tvar.i])
    {
        if (str[tvar.i] == '-')
            tvar.k++;
        if (tvar.k > 1)
            return(0);
        if (!ft_isdigit(str[tvar.i]) && str[tvar.i] != '-')
            return (0);
    }
    return (1);
}

int notnull_values(char **argv)
{
    int i;
    int c;

    i = 0;
    c = 0;
    while (argv[++i])
        if (argv[i] && argv[i][0])
            c++; 
    return (c);
}

int load_initial_values(char **argv, int **arr_num)
{
    int			c;
    int			i;
	long int	x;

    c = notnull_values(argv);
    *arr_num = (int*)malloc(c * sizeof(int)); 
    if (!arr_num)
        return (0);
    c = 0;
    i = 0;
    while (argv[++c])
    {
        if (argv[c] && argv[c][0])
        {
			if (ft_strlen(argv[c]) > 11)
				return (0);
			x = ft_atol(argv[c]);
			if (x < INT_MIN || x > INT_MAX)
				return (0);
            (*arr_num)[i] = ft_atoi(argv[c]);            
            i++;
        }
    }
    return (1);
}
