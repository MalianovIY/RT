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

#include "rt.h"

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
			d = gm_mat_pnt_mult(d, rt->t);
			color = trace_ray(rt, gm_mat_create(rt->o, d,
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
		ft_putstr("usage: need config file.\n");
	return (0);
}
