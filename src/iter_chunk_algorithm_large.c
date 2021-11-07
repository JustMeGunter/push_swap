/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_chunk_algorithm_large.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:38:39 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/07 20:29:29 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	iter_chunk(t_data *data, int **tmp_arr, t_vloop *vloop)
{
	int		s;
	int		l;

	l = 0;
	s = 0;
	while (l < data->n_chunks)
		if (data->c_chunk[l++] == data->tarr[vloop->i])
			s = 1;
	if ( !s && vloop->y == data->tarr[vloop->i])
		(*tmp_arr)[vloop->j++] = vloop->k;	
}
