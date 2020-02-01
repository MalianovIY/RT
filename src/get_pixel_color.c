/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:04:43 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/28 08:03:12 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_mat4		get_pn_torus(t_rt *rt, t_mat4 t)
{
	t_plane		s;
	t_mat4		pn;

	s = rt->obj.planes[(int)t.v[2].v[1]];
	pn.v[0] = gm_vec_add(t.v[0], gm_vec_alp_mult(t.v[1], t.v[2].v[0])); // doesnt work
	pn.v[1] = gm_vec_dot(t.v[1], s.norm) > 0 ? // doesnt work
			  gm_vec_minus(s.norm) : s.norm;
	return (pn);
}

t_mat4		get_pn(t_rt *rt, t_mat4 t, t_obj_type x)
{
	if (x == sphere)
		return (get_pn_sphere(rt, t));
	else if (x == cone)
		return (get_pn_cone(rt, t));
	else if (x == plane)
		return (get_pn_plane(rt, t));
	else if (x == cylinder)
		return (get_pn_cylinder(rt, t));
	else if (x == torus)
		return (get_pn_torus(rt, t));
	return (gm_mat_init_identity());
}

float		get_specular_obj(t_rt *rt, t_mat4 t, t_obj_type x)
{
	float	spec;

	spec = x == cone ? rt->obj.cones[(int)t.v[2].v[1]].id.v[3] : -1;
	spec = x == sphere ? rt->obj.spheres[(int)t.v[2].v[1]].id.v[3] : spec;
	spec = x == plane ? rt->obj.planes[(int)t.v[2].v[1]].id.v[3] : spec;
	spec = x == cylinder ? rt->obj.cylinders[(int)t.v[2].v[1]].id.v[3] : spec;
	spec = x == torus ? rt->obj.tors[(int)t.v[2].v[1]].id.v[3] : spec;
	return (spec);
}

float		get_reflect_obj(t_rt *rt, t_mat4 t, t_obj_type x)
{
	float	ref;

	ref = x == cone ? rt->obj.cones[(int)t.v[2].v[1]].data.v[0] : -1;
	ref = x == sphere ? rt->obj.spheres[(int)t.v[2].v[1]].data.v[0] : ref;
	ref = x == plane ? rt->obj.planes[(int)t.v[2].v[1]].data.v[0] : ref;
	ref = x == cylinder ? rt->obj.cylinders[(int)t.v[2].v[1]].data.v[0] : ref;
	ref = x == torus ? rt->obj.tors[(int)t.v[2].v[1]].data.v[0] : ref;
	return (ref);
}

t_int4		get_color_obj_light(t_rt *rt, t_mat4 t, t_obj_type x, float light)
{
	int		color;
	t_int4	argb;

	color = x == cone ? rt->obj.cones[(int)t.v[2].v[1]].id.v[2] : 0;
	color = x == sphere ? rt->obj.spheres[(int)t.v[2].v[1]].id.v[2] : color;
	color = x == plane ? rt->obj.planes[(int)t.v[2].v[1]].id.v[2] : color;
	color = x == cylinder ? rt->obj.cylinders[(int)t.v[2].v[1]].id.v[2] : color;
	color = x == torus ? rt->obj.tors[(int)t.v[2].v[1]].id.v[2] : color;
	argb.v[0] = 0;
	argb.v[1] = (color >> 16 & 0xFF) * light;
	argb.v[2] = (color >> 8 & 0xFF) * light;
	argb.v[3] = (color & 0xFF) * light;
	return (argb);
}

/*
**           t_mat4 t contains 4 vectors: o - point start ray,                *
**                    d ray vector, closest and lim.                          *
**                                                                            *
**         t_float4 closest contains distance to closest object               *
**                       and id closest sphere.                               *
**                                                                            *
**               t_float4 lim contains information about                      *
**              minimal, maximum intersection calculates                      *
**             and recursion depth and object_intersection                    *
**          or minus one if this is first ray for this object.                *
*/

t_int4		get_pixel_color(t_rt *rt, t_mat4 t, t_obj_type x)
{
	float		lr[2];
	t_int4		argb;
	t_int4		lcol;
	t_mat4		pn;
	t_d_obj 	d;

	pn.v[0] = gm_vec_add(t.v[0], gm_vec_alp_mult(t.v[1], t.v[2].v[0]));
	d = get_dist(rt, pn.v[0]);
	pn.v[1] = gm_vec_normalize(gm_vec_subtract(gm_init_float(d.ro,
			d.ro, d.ro, 0), gm_init_float(get_dist(rt, gm_vec_subtract(pn.v[0],
			gm_init_float(SURF_DIST, 0, 0, 0))).ro, get_dist(rt,
			gm_vec_subtract(pn.v[0], gm_init_float(0, SURF_DIST, 0, 0))).ro,
			get_dist(rt, gm_vec_subtract(pn.v[0], gm_init_float(0, 0,
					SURF_DIST, 0))).ro, 0)));
//	pn = get_pn(rt, t, x);
	lr[0] = lighting(rt, gm_mat_create(pn.v[0], gm_vec_minus(t.v[1]), pn.v[1],
			gm_init_float(t.v[2].v[1], get_specular_obj(rt, t, x), 0, 0)), x);
	argb = get_color_obj_light(rt, t, x, lr[0]);
	lr[1] = get_reflect_obj(rt, t, x);
	if ((t.v[3].v[2] > 0) && (lr[1] > 0))
	{
		t.v[3].v[2] -= 1;
//		lcol = trace_ray(rt, gm_mat_create(pn.v[0], gm_vec_reflect(
//				gm_vec_minus(t.v[1]), pn.v[1]),
//				gm_init_float(0, 0, 0, 0), t.v[3]));
		lcol = ray_march(rt, gm_mat_create(
				gm_vec_add(pn.v[0], gm_vec_alp_mult(pn.v[1], 0.01)),
				gm_vec_reflect(gm_vec_minus(t.v[1]), pn.v[1]),
				gm_init_float(0, 0, 0, 0),
				t.v[3]));
		argb.v[0] = argb.v[0] * (1 - lr[1]) + (lcol.v[0] & 0xFF) * lr[1] * 1;
		argb.v[1] = argb.v[1] * (1 - lr[1]) + (lcol.v[1] & 0xFF) * lr[1] * 1;
		argb.v[2] = argb.v[2] * (1 - lr[1]) + (lcol.v[2] & 0xFF) * lr[1] * 1;
		argb.v[3] = argb.v[3] * (1 - lr[1]) + (lcol.v[3] & 0xFF) * lr[1] * 1;
	}
	return (argb);
}
