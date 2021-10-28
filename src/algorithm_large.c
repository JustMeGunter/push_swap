/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:21:40 by acrucesp          #+#    #+#             */
/*   Updated: 2021/10/28 22:14:31 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		num_chunks(int c)
{
	int		result;
	float	div;

	div = 2;
	result = 0;
	while (result > (0.2 * c) || result == 0)
		result = c / div++;
	return (div - 1);
}

void	algorithm_large(t_data *data)
{
	int		n_chunks;
	int		tmp;

	n_chunks = num_chunks(data->c + 1); 
	if ((data->c + 1) - (n_chunks * ((data->c + 1) / n_chunks)) != 0)
		tmp = n_chunks + 1;
	else
		tmp = n_chunks;
	printf("\nsize:%i, num:%i, data->c: %i\n",  (data->c + 1) / n_chunks, tmp, data->c + 1);
}
