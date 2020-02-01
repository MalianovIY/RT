/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 03:59:58 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/28 09:07:51 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_d_obj get_dist(t_rt *rt, t_float4 p)
{
	int			i;
	float		s, s1;
	t_d_obj		res;
	t_float4	oc;

	i = -1;
	res.id = -1;
	res.obj = none;
	res.ro = INF;
	while (++i < rt->obj.count_obj[0])
	{
		s = gm_vec_dot(gm_vec_subtract(p,  rt->obj.planes[i].point), rt->obj.planes[i].norm); //gm_vec_len(gm_vec_subtract(p, rt->obj.spheres[i].center));
		res.ro = s < res.ro ? s : res.ro;
		res.id = s == res.ro ? i : res.id;
		res.obj = s == res.ro ? plane : res.obj;
	}
	i = -1;
	while (++i < rt->obj.count_obj[1])
	{
		s = gm_vec_len(gm_vec_mult(gm_vec_subtract(p, rt->obj.cylinders[i].center), rt->obj.cylinders[i].norm)) - rt->obj.cylinders[i].data.v[1];
		res.ro = s < res.ro ? s : res.ro;
		res.id = s == res.ro ? i : res.id;
		res.obj = s == res.ro ? cylinder : res.obj;
	}
	i = -1;
	while (++i < rt->obj.count_obj[2])
	{
		s = gm_vec_len(gm_vec_subtract(rt->obj.spheres[i].center, p)) - rt->obj.spheres[i].data.v[1];
		res.ro = s < res.ro ? s : res.ro;
		res.id = s == res.ro ? i : res.id;
		res.obj = s == res.ro ? sphere : res.obj;
	}
	i = -1;
	while (++i < rt->obj.count_obj[3])
	{
		oc = gm_vec_subtract(rt->obj.cones[i].center, p);
		s = gm_vec_len(gm_vec_mult(oc, gm_vec_normalize(gm_vec_vec_rotate(rt->obj.cones->norm, gm_vec_mult(oc,rt->obj.cones[i].norm), -atan(rt->obj.cones[i].data.v[1]) / 2))));
		s1 = gm_vec_len(gm_vec_mult(oc, gm_vec_normalize(gm_vec_vec_rotate(rt->obj.cones->norm, gm_vec_mult(oc,rt->obj.cones[i].norm), atan(rt->obj.cones[i].data.v[1]) / 2))));
		s = s1 > s ? s : s1;//its doest work
		res.ro = s < res.ro ? s : res.ro;
		res.id = s == res.ro ? i : res.id;
		res.obj = s == res.ro ? cone : res.obj;
	}
	return (res);
}

t_int4	ray_march(t_rt *rt, t_mat4 t)
{
	float	ro;
	t_d_obj	ds;
	int		i;

	ro = 0;
	i = -1;
	while (++i < MAX_STEPS)
	{
		ds = get_dist(rt, gm_vec_add(t.v[0], gm_vec_alp_mult(t.v[1], ro)));
		ro += ds.ro;
		if ((ro + 0.01) >= MAX_DIST || ds.ro < SURF_DIST)
			break ;
	}
	if (ds.id == -1 || ro + SURF_DIST >= MAX_DIST)
		return (gm_init_int(BG_COLOR >> 24 & 0xFF, BG_COLOR >> 16 & 0xFF,
				BG_COLOR >> 8 & 0xFF, BG_COLOR & 0xFF));
	t.v[2] = gm_init_float(ro, ds.id, 0, 0);
	return (get_pixel_color(rt, t, ds.obj));
}

t_int4	trace_ray(t_rt *rt, t_mat4 t)
{
	t_float4	t1;
	t_obj_type	x;

	x = sphere;
	t.v[2] = closest_intersect_sphere(rt, t.v[0], t.v[1], t.v[3]);
	t1 = closest_intersect_cone(rt, t.v[0], t.v[1], t.v[3]);
	x = (t.v[2].v[0] > t1.v[0]) ? cone : x;
	t.v[2] = (t.v[2].v[0] > t1.v[0]) ? t1 : t.v[2];
	t1 = closest_intersect_cylinder(rt, t.v[0], t.v[1], t.v[3]);
	x = (t.v[2].v[0] > t1.v[0]) ? cylinder : x;
	t.v[2] = (t.v[2].v[0] > t1.v[0]) ? t1 : t.v[2];
	t1 = closest_intersect_plane(rt, t.v[0], t.v[1], t.v[3]);
	x = (t.v[2].v[0] > t1.v[0]) ? plane : x;
	t.v[2] = (t.v[2].v[0] > t1.v[0]) ? t1 : t.v[2];
	if (t.v[2].v[1] == -1)
		return (gm_init_int(BG_COLOR >> 24 & 0xFF, BG_COLOR >> 16 & 0xFF,
							BG_COLOR >> 8 & 0xFF, BG_COLOR & 0xFF));
	else
		return (get_pixel_color(rt, t, x));
}

void	calc(t_rt *rt)
{
	int			x;
	int			y;
	t_float4	d;
	t_int4		color;

	x = -rt->scr.v[2] - 1;
	while (++x < rt->scr.v[2] + 1)
	{
		y = -rt->scr.v[3] - 1;
		while (++y < rt->scr.v[3] + 1)
		{
			d = gm_vec_subtract(gm_init_float(
					(float)(x * (rt->cnv.v[0] / rt->scr.v[0]) + rt->o.v[0]),
					(float)(y * (rt->cnv.v[1] / rt->scr.v[1]) + rt->o.v[1]),
					rt->cnv.v[2] + rt->o.v[2], 0), rt->o);
			d = gm_vec_normalize(gm_mat_pnt_mult(d, rt->t));
//			color = trace_ray(rt, gm_mat_create(rt->o, d,
//					gm_init_float(0, 0, 0, 0),
//					gm_init_float(1, INF, REC_DEPTH, -1)));
			color = ray_march(rt, gm_mat_create(rt->o, d,
					gm_init_float(0, 0, 0, 0),
					gm_init_float(1, INF, REC_DEPTH, -1)));
			draw_point(rt, rt->scr.v[2] + x,
					rt->scr.v[3] - y, color);
		}
	}
	image_to_win(rt);
}

void	error_exit(void)
{
	ft_putstr("config file doesn't exist\n");
	exit(0);
}

int		main(int argc, char *argv[])
{
	t_rt		rt;

	if (argc == 2)
	{
		rt.mlx.win = NULL;
		rt.mlx.mlx = NULL;
		ft_strcpy(rt.filename, argv[1]);
		init_scene(&rt, rt.filename);
		calc(&rt);
		mlx_loop(rt.mlx.mlx);
	}
	else
		ft_putstr("usage: need one config file.\n");
	return (0);
}
