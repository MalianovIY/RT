/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:13:08 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/05 22:13:08 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_light	init_light(t_int4 id, t_light_type type, t_float4 vec, float intns)
{
	t_light	a;

	a.id = id;
	a.type = type;
	a.pos = vec;
	a.intn = intns;
	return (a);
}

/*
**         t_mat4 t contains 4 vectors: p - point intersection,               *
**       d ray vector, norm and [object_id, specular, max value, i].          *
*/

float	specular_and_diffuse(float intens, t_mat4 t, t_float4 l, t_obj_type x)
{
	float		nl;
	float		rv;
	t_float4	r;

	if ((nl = gm_vec_dot(t.v[2], l)) > 0)
		t.v[3].v[3] += intens * nl / (gm_vec_len(t.v[2])
				* gm_vec_len(l));
	if (t.v[3].v[1] > 0)
	{
		r = gm_vec_reflect(l, t.v[2]);
		if ((rv = gm_vec_dot(r, t.v[1])) > 0)
			t.v[3].v[3] += intens * pow(rv / (gm_vec_len(r)
					* gm_vec_len(t.v[1])), t.v[3].v[1]);
	}
	return (t.v[3].v[3]);
}

/*
**         t_mat4 t contains 4 vectors: p - point intersection,               *
**         d ray vector, norm and [object_id, specular, max, 0].              *
*/

int		shadow(t_rt *rt, t_mat4 t, t_float4 l, t_obj_type x)
{
	if ((closest_intersect_sphere(rt, t.v[0], l,
			gm_init_float(0.f, t.v[3].v[2], 0.f,
					x == sphere ? (float)t.v[3].v[0] : -1.f)).v[1] != -1)
			|| (closest_intersect_cone(rt, t.v[0], l,
					gm_init_float(0.f, t.v[3].v[2], 0.f,
					x == cone ? (float)t.v[3].v[0] : -1.f)).v[1] != -1)
			|| (closest_intersect_cylinder(rt, t.v[0], l,
					gm_init_float(0.f, t.v[3].v[2], 0.f,
					x == cylinder ? (float)t.v[3].v[0] : -1.f)).v[1] != -1))
		return (1);
	return (0);
}

/*
**         t_mat4 t contains 4 vectors: p - point intersection,               *
**       d ray vector, norm and [object_id, specular, max value, i].          *
*/

float	lighting(t_rt *rt, t_mat4 t, t_obj_type x)
{
	int			j;
	t_float4	l;

	j = -1;
	while (++j < rt->obj.count_obj[4])
	{
		if (rt->obj.lights[j].type == ambient)
		{
			t.v[3].v[3] += rt->obj.lights[j].intn;
			continue ;
		}
		else
		{
			t.v[3].v[2] = rt->obj.lights[j].type == dir ? INF : 0.f;
			l = rt->obj.lights[j].type == dir ? rt->obj.lights[j].pos :
				gm_vec_subtract(rt->obj.lights[j].pos, t.v[0]);
		}
		if (shadow(rt, t, l, x))
			continue ;
		t.v[3].v[3] = specular_and_diffuse(rt->obj.lights[j].intn, t, l, x);
	}
	return (t.v[3].v[3]);
}
