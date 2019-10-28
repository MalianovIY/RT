/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 03:59:58 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/28 09:03:07 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cone		init_cone(t_int4 id, t_float4 center, t_float4 norm, t_float4 data)
{
	t_cone	a;

	a.center = center;
	a.norm = norm;
	a.id = id;
	a.data = data;
	return (a);
}

/*
**           t_mat4 t contains 4 vectors: o - point start ray,                *
**                    d ray vector, closest and lim.                          *
**                                                                            *
**          t_float4 closest contains distance to closest cone                *
**                        and id closest cone.                                *
**                                                                            *
**               t_float4 lim contains information about                      *
**              minimal, maximum intersection calculates                      *
**              and recursion depth and cone_intersection                     *
**           or minus one if this is first ray for this cone.                 *
*/

t_mat4		get_pn_cone(t_rt *rt, t_mat4 t)
{
	t_cone		s;
	t_mat4		pn;
	t_float4	t1;

	s = rt->obj.cones[(int)t.v[2].v[1]];
	pn.v[0] = gm_vec_add(t.v[0], gm_vec_alp_mult(t.v[1], t.v[2].v[0]));
	t1 = gm_vec_normalize(gm_vec_subtract(pn.v[0], s.center));
	pn.v[1] = gm_vec_normalize(gm_vec_subtract(t1, gm_vec_cos(s.norm, t1) > 0 ?
										s.norm : gm_vec_minus(s.norm)));
	return (pn);
}

t_float4	intersect_ray_cone(t_float4 o, t_float4 d, t_cone cone)
{
	float		kd[4];
	float		dv;
	float		xv;
	t_float4	t;
	t_float4	co;

	ft_memcpy(t.v, "\x00\x00\x80\xbf\x00\x00\x80\xbf\x00"
				"\x00\x80\xbf\x00\x00\x80\xbf", sizeof(float) * 4);
	co = gm_vec_subtract(o, cone.center);
	xv = gm_vec_dot(co, cone.norm);
	dv = gm_vec_dot(d, cone.norm);
	kd[0] = gm_vec_dot(d, d) - dv * dv * (1 + cone.data.v[1] * cone.data.v[1]);
	kd[1] = 2 * (gm_vec_dot(d, co)
			- dv * xv * (1 + cone.data.v[1] * cone.data.v[1]));
	kd[2] = gm_vec_dot(co, co)
			- xv * xv * (1 + cone.data.v[1] * cone.data.v[1]);
	kd[3] = kd[1] * kd[1] - 4 * kd[0] * kd[2];
	if (kd[3] < 0)
		return (t);
	kd[3] = sqrt(kd[3]);
	t.v[0] = (-kd[1] + kd[3]) / (2 * kd[0]);
	t.v[1] = (-kd[1] - kd[3]) / (2 * kd[0]);
	return (t);
}

t_float4	closest_intersect_cone(t_rt *rt, t_float4 o,
		t_float4 d, t_float4 lim)
{
	int			iid[2];
	float		clos;
	t_float4	intrs;

	ft_memset(iid, 0xffffffff, sizeof(int) * 2);
	clos = INF;
	while (++(iid[0]) < rt->obj.count_obj[3])
	{
		if ((int)lim.v[3] == iid[0])
			continue ;
		intrs = intersect_ray_cone(o, d, rt->obj.cones[iid[0]]);
		if (intrs.v[0] > lim.v[0] && intrs.v[0] < lim.v[1])
			if (clos > intrs.v[0])
				clos = intrs.v[0];
		if (intrs.v[1] > lim.v[0] && intrs.v[1] < lim.v[1])
			if (clos > intrs.v[1])
				clos = intrs.v[1];
		iid[1] = (clos == intrs.v[0] || clos == intrs.v[1]) ? iid[0] : iid[1];
	}
	return (gm_init_float(clos, iid[1], 0.f, 0.f));
}
