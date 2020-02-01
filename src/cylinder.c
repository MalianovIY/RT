/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 04:56:41 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/28 08:02:50 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_cylinder	init_cylinder(t_int4 id, t_float4 center,
		t_float4 norm, t_float4 data)
{
	t_cylinder	a;

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
**        t_float4 closest contains distance to closest cylinder              *
**                       and id closest sphere.                               *
**                                                                            *
**               t_float4 lim contains information about                      *
**              minimal, maximum intersection calculates                      *
**            and recursion depth and cylinder_intersection                   *
**         or minus one if this is first ray for this cylinder.               *
*/

t_mat4		get_pn_cylinder(t_rt *rt, t_mat4 t)
{
	t_cylinder	s;
	t_mat4		pn;

	s = rt->obj.cylinders[(int)t.v[2].v[1]];
	pn.v[0] = gm_vec_add(t.v[0], gm_vec_alp_mult(t.v[1], t.v[2].v[0]));
	pn.v[1] = gm_vec_normalize(gm_vec_ortog(t.v[1], s.norm));
	return (pn);
}

t_float4	intersect_ray_cylinder(t_float4 o, t_float4 d, t_cylinder c)
{
	float		kd[6];
	t_float4	t;
	t_float4	co;

	ft_memcpy(t.v, "\x00\x00\x80\xbf\x00\x00\x80\xbf\x00"
				"\x00\x80\xbf\x00\x00\x80\xbf", sizeof(float) * 4);
	co = gm_vec_subtract(o, c.center);
	kd[5] = gm_vec_dot(co, c.norm);
	kd[4] = gm_vec_dot(d, c.norm);
	kd[0] = gm_vec_dot(d, d) - kd[4] * kd[4];
	kd[1] = 2 * (gm_vec_dot(d, co) - kd[4] * kd[5]);
	kd[2] = gm_vec_dot(co, co) - kd[5] * kd[5] - c.data.v[1] * c.data.v[1];
	kd[3] = kd[1] * kd[1] - 4 * kd[0] * kd[2];
	if (kd[3] < 0)
		return (t);
	kd[3] = sqrt(kd[3]);
	t.v[0] = (-kd[1] + kd[3]) / (2 * kd[0]);
	t.v[1] = (-kd[1] - kd[3]) / (2 * kd[0]);
	return (t);
}

t_float4	closest_intersect_cylinder(t_rt *rt, t_float4 o,
		t_float4 d, t_float4 lim)
{
	int			iid[2];
	float		clos;
	t_float4	intrs;

	ft_memset(iid, 0xffffffff, sizeof(int) * 2);
	clos = INF;
	while (++(iid[0]) < rt->obj.count_obj[1])
	{
		if ((int)lim.v[3] == iid[0])
			continue ;
		intrs = intersect_ray_cylinder(o, d, rt->obj.cylinders[iid[0]]);
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
