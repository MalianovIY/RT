/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 03:59:58 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/28 08:03:50 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_sphere	init_sphere(t_int4 id, t_float4 data, t_float4 center)
{
	t_sphere	a;

	a.center = center;
	a.id = id;
	a.data = data;
	return (a);
}

/*
**            t_mat4 t contains 4 vectors: o - point start ray,               *
**                     d ray vector, closest and lim.                         *
**          t_float4 closest contains distance to closest sphere              *
**                        and id closest sphere.                              *
**                t_float4 lim contains information about                     *
**               minimal, maximum intersection calculates                     *
**             and recursion depth and sphere_intersection                    *
**           or minus one if this is first ray for this sphere.               *
*/

t_mat4		get_pn_sphere(t_rt *rt, t_mat4 t)
{
	t_sphere	s;
	t_mat4		pn;

	s = rt->obj.spheres[(int)t.v[2].v[1]];
	pn.v[0] = gm_vec_add(t.v[0], gm_vec_alp_mult(t.v[1], t.v[2].v[0]));
	pn.v[1] = gm_vec_normalize(gm_vec_subtract(pn.v[0], s.center));
	return (pn);
}

t_float4	intersect_ray_sphere(t_float4 o, t_float4 d, t_sphere sphere)
{
	float		kd[4];
	t_float4	t;
	t_float4	oc;

	ft_memcpy(t.v, "\x00\x00\x80\xbf\x00\x00\x80\xbf\x00"
				"\x00\x80\xbf\x00\x00\x80\xbf", sizeof(float) * 4);
	oc = gm_vec_subtract(o, sphere.center);
	kd[0] = gm_vec_dot(d, d);
	kd[1] = 2 * gm_vec_dot(oc, d);
	kd[2] = gm_vec_dot(oc, oc) - sphere.data.v[1] * sphere.data.v[1];
	kd[3] = kd[1] * kd[1] - 4 * kd[0] * kd[2];
	if (kd[3] < 0)
		return (t);
	kd[3] = sqrt(kd[3]);
	t.v[0] = (-kd[1] + kd[3]) / (2 * kd[0]);
	t.v[1] = (-kd[1] - kd[3]) / (2 * kd[0]);
	return (t);
}

t_float4	closest_intersect_sphere(t_rt *rt, t_float4 o,
		t_float4 d, t_float4 lim)
{
	int			iid[2];
	float		clos;
	t_float4	intrs;

	iid[0] = -1;
	iid[1] = -1;
	clos = INF;
	while (++(iid[0]) < rt->obj.count_obj[2])
	{
		if ((int)lim.v[3] == iid[0])
			continue ;
		intrs = intersect_ray_sphere(o, d, rt->obj.spheres[iid[0]]);
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
