/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 05:25:46 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/28 08:03:39 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_plane		init_plane(t_int4 id, t_float4 point, t_float4 norm, t_float4 data)
{
	t_plane	a;

	a.point = point;
	a.norm = norm;
	a.id = id;
	a.data = data;
	return (a);
}

/*
**           t_mat4 t contains 4 vectors: o - point start ray,                *
**                    d ray vector, closest and lim.                          *
**                                                                            *
**         t_float4 closest contains distance to closest plane                *
**                       and id closest plane.                                *
**                                                                            *
**               t_float4 lim contains information about                      *
**              minimal, maximum intersection calculates                      *
**             and recursion depth and plane_intersection                     *
**          or minus one if this is first ray for this plane.                 *
*/

t_mat4		get_pn_plane(t_rt *rt, t_mat4 t)
{
	t_plane		s;
	t_mat4		pn;

	s = rt->obj.planes[(int)t.v[2].v[1]];
	pn.v[0] = gm_vec_add(t.v[0], gm_vec_alp_mult(t.v[1], t.v[2].v[0]));
	pn.v[1] = gm_vec_dot(t.v[1], s.norm) > 0 ?
			gm_vec_minus(s.norm) : s.norm;
	return (pn);
}

float		intersect_ray_plane(t_float4 o, t_float4 d, t_plane p)
{
	float dv;

	if ((dv = gm_vec_dot(d, p.norm)))
		return (-gm_vec_dot(gm_vec_subtract(o, p.point), p.norm) / dv);
	else
		return (-1.f);
}

t_float4	closest_intersect_plane(t_rt *rt, t_float4 o,
		t_float4 d, t_float4 lim)
{
	int		iid[2];
	float	closest;
	float	intsec;

	ft_memset(iid, 0xffffffff, sizeof(int) * 2);
	closest = INF;
	while (++(iid[0]) < rt->obj.count_obj[0])
	{
		if ((int)lim.v[3] == iid[0])
			continue ;
		intsec = intersect_ray_plane(o, d, rt->obj.planes[iid[0]]);
		if (intsec > lim.v[0] && intsec < lim.v[1])
			if (closest > intsec)
			{
				closest = intsec;
				iid[1] = iid[0];
			}
	}
	return (gm_init_float(closest, iid[1], 0.f, 0.f));
}
