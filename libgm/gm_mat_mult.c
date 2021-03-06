/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_mat_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:12:10 by ahorker           #+#    #+#             */
/*   Updated: 2019/05/02 21:12:10 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libgm.h"

t_mat4	gm_mat_mult(t_mat4 t1, t_mat4 t2)
{
	t_mat4	t;
	int		i[3];

	t = gm_mat_init_identity();
	i[0] = -1;
	while (++(i[0]) < 4)
	{
		t.v[i[0]].v[i[0]] = 0;
		i[1] = -1;
		while (++(i[1]) < 4)
		{
			i[2] = -1;
			while (++(i[2]) < 4)
				t.v[i[0]].v[i[1]] += t1.v[i[0]].v[i[2]] * t2.v[i[2]].v[i[1]];
		}
	}
	return (t);
}
