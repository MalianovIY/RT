/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_mat_inversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:12:10 by ahorker           #+#    #+#             */
/*   Updated: 2019/05/02 21:12:10 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libgm.h"

static t_mat4	mat_invhlp(t_mat4 t0)
{
	int		i[3];
	t_mat4	t;

	i[2] = -1;
	while (++i[2] < 4)
	{
		i[1] = -1;
		while (++i[1] < 4)
		{
			t0.v[i[2]].v[i[1]] /= t0.v[i[2]].v[i[2]];
			t.v[i[2]].v[i[1]] /= t0.v[i[2]].v[i[2]];
		}
		i[0] = i[2];
		while (++i[0] < 4)
		{
			i[1] = -1;
			while (++i[1] < 4)
			{
				t0.v[i[0]].v[i[1]] -= t0.v[i[2]].v[i[1]] * t0.v[i[0]].v[i[2]];
				t.v[i[0]].v[i[1]] -= t.v[i[2]].v[i[1]] * t0.v[i[0]].v[i[2]];
			}
		}
	}
	return (t);
}

t_mat4			gm_mat_inversion(t_mat4 t0)
{
	float	temp;
	t_mat4	t;
	int		i[3];

	t = mat_invhlp(t0);
	i[2] = 4;
	while (--i[2] > 0)
	{
		i[0] = i[2];
		while (--i[0] >= 0)
		{
			temp = t0.v[i[0]].v[i[2]];
			i[1] = -1;
			while (++i[1] < 4)
			{
				t0.v[i[0]].v[i[1]] -= t0.v[i[2]].v[i[1]] * temp;
				t.v[i[0]].v[i[1]] -= t.v[i[2]].v[i[1]] * temp;
			}
		}
	}
	return (t);
}
