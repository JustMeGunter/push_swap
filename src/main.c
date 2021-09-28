/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:25:20 by acrucesp          #+#    #+#             */
/*   Updated: 2021/09/18 19:01:03 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>
#include <stdio.h>

//to libft
int digit_parser(char *str)
{
    int i;
    int s;

    i = -1;
    s = 0;
    if (!str[0])
        return (0);
    while (str[++i])
    {
        printf("%c", str[i]);
        if (str[i] == '-')
            s++;
        if (s > 1)
            return(0);
        if (!ft_isdigit(str[i]) && str[i] != '-')
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
    int c;
    int i;

    c = notnull_values(argv);
    *arr_num = (int*)malloc((c + 1) * sizeof(int)); 
    if (!arr_num)
        return (0);
    c = 0;
    i = 0;
    while (argv[++c])
    {
        if (argv[c] && argv[c][0])
        {
            (*arr_num)[i] = ft_atoi(argv[c]);            
            i++;
            printf("arr: %i, argv: %i i: %i\n", (*arr_num)[i - 1], ft_atoi(argv[c]), i);
        }
    }
    arr_num[i + 1] = 0;
    return (1);
}

int	main(int argc, char *argv[])
{
	//t_stack *stack_a;
    int *arr;
    int c;

	if (argc < 3)
	{
		write(1, "Error\n", 6);
	}		
    c = 0;
    while (argv[++c])
        if (!digit_parser(argv[c]))
            return (0);
    printf("HELLO\n");
    if (!load_initial_values(argv, &arr))
        return(0);
    printf("HELLO2\n");
    c = 0;
    while (arr[c])
    {
        printf("%i e\n", arr[c]);
        c++;
    }
}
