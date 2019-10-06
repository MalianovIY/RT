/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_prog.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 23:00:20 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/05 23:00:20 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_scene_1(t_rt *rt)
{
	rt->obj.spheres[0] = init_sphere(gm_init_int(0, 0, 0xFF0000, 1000),
			gm_init_float(0., 1, 0, 0), gm_init_float(0, 0, 3, 0));
	rt->obj.count_obj[2]++;
	rt->obj.spheres[1] = init_sphere(gm_init_int(1, 1, 0x0000FF, 500),
			gm_init_float(.3, 1, 0, 0), gm_init_float(2, 2, 3, 0));
	rt->obj.count_obj[2]++;
	rt->obj.spheres[2] = init_sphere(gm_init_int(2, 2, 0x00FF00, 10),
			gm_init_float(.0, 1, 0, 0), gm_init_float(-2, 2, 3, 0));
	rt->obj.count_obj[2]++;
	rt->obj.planes[0] = init_plane(gm_init_int(0, 3, 0xFFFFFF, 100),
			gm_init_float(0., -0.05, 0, 0), gm_init_float(0, -1, 0, 0),
			gm_init_float(0.009, 0, 0, 0));
	rt->obj.count_obj[0]++;
	rt->obj.lights[4] = init_light(gm_init_int(0, 4, 0, 0), ambient,
			gm_init_float(0, 0, 0, 0), 0.2);
	rt->obj.count_obj[4]++;
	rt->obj.lights[0] = init_light(gm_init_int(1, 5, 0, 0), point,
			gm_init_float(0.3, 1.8, 2.5, 0), .2);
	rt->obj.count_obj[4]++;
	rt->obj.lights[1] = init_light(gm_init_int(2, 6, 0, 0), point,
			gm_init_float(-2, 5, 2, 0), 0.2);
	rt->obj.count_obj[4]++;
	rt->obj.lights[2] = init_light(gm_init_int(3, 7, 0, 0), dir,
			gm_init_float(1, 4, 4, 0), 0.1);
	rt->obj.count_obj[4]++;
}

void	init_scene_2(t_rt *rt)
{
	rt->obj.lights[3] = init_light(gm_init_int(4, 8, 0, 0), dir,
			gm_init_float(-1, -4, -4, 0), 0.2);
	rt->obj.count_obj[4]++;
	rt->obj.cones[0] = init_cone(gm_init_int(0, 9, 0xFF00FF, 100),
			gm_init_float(0, 4, 6, 0), gm_vec_normalize(
					gm_init_float(0, 1, 0, 0)), gm_init_float(0.2, 0.3, 0, 0));
	rt->obj.count_obj[3]++;
	rt->obj.cylinders[0] = init_cylinder(gm_init_int(0, 10, 0x00FFFF, 1000),
			gm_init_float(-3, -2, 4, 0), gm_vec_normalize(
				gm_init_float(0, 1, 0, 0)), gm_init_float(0.3, 1, 0, 0));
	rt->obj.count_obj[1]++;
	rt->obj.planes[1] = init_plane(gm_init_int(1, 11, 0xFFFFFF, 100),
			gm_init_float(0., 0., 7, 0), gm_init_float(0., 0, -1, 0),
			gm_init_float(0.0009, 0., 0., 0.));
	rt->obj.count_obj[0]++;
	rt->obj.spheres[3] = init_sphere(gm_init_int(3, 12, 0xFFFFFF, 10),
			gm_init_float(.0, 1, 0, 0), gm_init_float(0, 0, 0, 0));
	rt->obj.count_obj[2]++;
	rt->obj.planes[2] = init_plane(gm_init_int(2, 13, 0xFFFFFF, 100),
			gm_init_float(0., 7, 0, 0), gm_init_float(0., 1, 0, 0),
			gm_init_float(0.009, 0., 0., 0.));
	rt->obj.count_obj[0]++;
}

void	init_scene_prog(t_rt *rt)
{
	ft_bzero(rt->obj.count_obj, 5 * sizeof(int));
	rt->o = gm_init_float(0.f, 1.0f, -2.f, 0.f);
	rt->t = gm_mat_create(gm_init_float(1, 0, 0, 0), gm_init_float(0, 1, 0, 0),
			gm_init_float(0, 0, 1, 0), gm_init_float(0, 0, 0, 1));
	rt->obj.planes[3] = init_plane(gm_init_int(3, 14, 0xFFFFFF, 100),
			gm_init_float(10, 0., 0, 0), gm_init_float(-1, 0, 0, 0),
			gm_init_float(0.0009, 0., 0., 0.));
	rt->obj.count_obj[0]++;
	rt->obj.planes[4] = init_plane(gm_init_int(4, 15, 0xFFFFFF, 10),
			gm_init_float(-10, 0., 0, 0), gm_init_float(1, 0, 0, 0),
			gm_init_float(0.09, 0., 0., 0.));
	rt->obj.count_obj[0]++;
	rt->obj.planes[5] = init_plane(gm_init_int(5, 16, 0xFFFFFF, 100),
			gm_init_float(0, 0., -10, 0), gm_init_float(0, 0, 1, 0),
			gm_init_float(0.009, 0., 0., 0.));
	rt->obj.count_obj[0]++;
	rt->obj.spheres[3] = init_sphere(gm_init_int(3, 17, 0x00FF00, 100),
			gm_init_float(.0, 1000, 0, 0), gm_init_float(0, -1001, 4, 0));
	rt->obj.count_obj[2]++;
	init_scene_1(rt);
	init_scene_2(rt);
	rt->scr = gm_init_int(320, 180, 160, 90);
	rt->cnv = gm_init_float(0.001f * 16.f / 9.f, 0.001f, 0.001, 0);
}
