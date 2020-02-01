/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:19:38 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/28 09:08:04 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "./libft.h"
# include "./libgm.h"

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>

# define INF		(1000.0f)
# define BG_COLOR	(0x4488FF)
# define REC_DEPTH	(2.f)
# define MAX_STEPS	(1000)
# define MAX_DIST	(1000.)
# define SURF_DIST	(.01)

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bit_per_pix;
	int				size_len;
	int				endian;
	char			*string;
}					t_mlx;

/*
**typedef struct		s_triangle
**{
**	t_int4			id;
**	t_float4		point[3];
**	t_float4		norm;
**	int				color;
**}					t_triangle;
*/

typedef enum		e_light_type
{					ambient, point, dir
}					t_light_type;

typedef enum		e_obj_type
{					cone, sphere, plane, cylinder, torus, none
}					t_obj_type;


typedef enum		e_obj_cons
{					apb, amb, bma, axb // a plus b, a minus b, b minus a, a multiply b
}					t_obj_cons;

typedef struct		s_light
{
	t_int4			id;
	t_light_type	type;
	t_float4		pos;
	float			intn;
}					t_light;

/*
**                  t_int4 id contains information about                      *
**                    id, global_id, color and specular                       *
**                             for this plane.                                *
**       t_float4 point and t_float4 norm contains information about          *
**                     normal and point fo this plane                         *
**               t_float4 data contains information about                     *
**                        reflection for this plane.                          *
*/

typedef struct		s_plane
{
	t_int4			id;
	t_float4		point;
	t_float4		norm;
	t_float4		data;
}					t_plane;

typedef struct		s_torus
{
	t_int4			id;
	t_float4		point;
	t_float4		norm;
	t_float4		data;
}					t_torus;

/*
**                   t_int4 id contains information about                     *
**                    id, global_id, color and specular                       *
**                              for this sphere.                              *
**                 t_float4 data contains information about                   *
**                           reflection and radius                            *
**                              for this sphere.                              *
*/

typedef struct		s_sphere
{
	t_int4			id;
	t_float4		data;
	t_float4		center;
}					t_sphere;

/*
**                  t_int4 id contains information about                      *
**                    id, global_id, color and specular                       *
**                            for this cone.                                  *
**                t_float4 data contains information about                    *
**                 reflection and tan_tetta for this cone.                    *
*/

typedef struct		s_cone
{
	t_int4			id;
	t_float4		center;
	t_float4		norm;
	t_float4		data;
}					t_cone;

/*
**                  t_int4 id contains information about                      *
**                    id, global_id, color and specular                       *
**                            for this cylinder.                              *
**                   t_float4 data contains information                       *
**             about reflection and radius for this cylinder.                 *
*/

typedef struct		s_cylinder
{
	t_int4			id;
	t_float4		center;
	t_float4		norm;
	t_float4		data;
}					t_cylinder;

typedef struct		s_defenition_composed
{
	t_obj_type		a_type;
	t_obj_type		b_type;
	int				g_id[3];
			// g_id - {id resault obj,
			// 			id obj a,
			// 			id obj b}
	t_obj_cons		x;
}					t_d_cobj;

typedef struct		s_defenition_object
{
	t_obj_type		obj;
	int				id;
	float			ro;
}					t_d_obj;

typedef struct		s_composed
{
	t_d_cobj		compose[50];
}					t_cobj;


typedef struct		s_obj
{
	int				count_obj[5];

	t_plane			planes[10];
	t_cylinder		cylinders[10];
	t_sphere		spheres[10];
	t_cone			cones[10];
	t_light			lights[10];
	t_torus			tors[10];
}					t_obj;

typedef struct		s_rt
{
	t_mlx			mlx;
	char			filename[1024];
	t_obj			obj;
	t_int4			scr;
	t_float4		cnv;
	t_mat4			t;
	t_float4		o;
}					t_rt;

t_d_obj get_dist(t_rt *rt, t_float4 p);

void				draw_point(t_rt *rt, int x, int y, t_int4 p);

void				init_mlx(t_rt *rt);

void				image_to_win(t_rt *rt);

int					deal_key(int key, void *param);

int					close_win(void *param);

t_int4				trace_ray(t_rt *rt, t_mat4 t);

t_int4				ray_march(t_rt *rt, t_mat4 t);

void				calc(t_rt *rt);

void				init_scene(t_rt *rt, char *c);

t_light				init_light(t_int4 id, t_light_type type, t_float4 vec,
								float intens);

t_cone				init_cone(t_int4 id, t_float4 center, t_float4 norm,
								t_float4 data);

t_sphere			init_sphere(t_int4 id, t_float4 data,
								t_float4 center);

t_cylinder			init_cylinder(t_int4 id, t_float4 center, t_float4 norm,
								t_float4 data);

t_plane				init_plane(t_int4 id, t_float4 point, t_float4 norm,
								t_float4 data);

t_float4			closest_intersect_cone(t_rt *rt, t_float4 o, t_float4 d,
												t_float4 lim);

t_float4			closest_intersect_sphere(t_rt *rt, t_float4 o, t_float4 d,
												t_float4 lim);

t_float4			closest_intersect_cylinder(t_rt *rt, t_float4 o,
												t_float4 d, t_float4 lim);

t_float4			closest_intersect_plane(t_rt *rt, t_float4 o, t_float4 d,
												t_float4 lim);

t_int4				get_pixel_color(t_rt *rt, t_mat4 t, t_obj_type x);

float				lighting(t_rt *rt, t_mat4 t, t_obj_type x);

t_mat4				get_pn_sphere(t_rt *rt, t_mat4 t);

t_mat4				get_pn_cone(t_rt *rt, t_mat4 t);

t_mat4				get_pn_cylinder(t_rt *rt, t_mat4 t);

t_mat4				get_pn_plane(t_rt *rt, t_mat4 t);

t_float4			split_float4(char *s, char c);

void				parse_cone(char **splits, int i, t_cone *t, char c);

void				parse_sphere(char **splits, int i, t_sphere *t, char c);

void				parse_cylinder(char **splits, int i, t_cylinder *t, char c);

void				parse_plane(char **splits, int i, t_plane *t, char c);

void				parse_light(char **splits, int i, t_light *t, char c);

void				read_cone(t_rt *rt, char **splits, char c, int *x);

void				read_sphere(t_rt *rt, char **splits, char c, int *x);

void				read_cylinder(t_rt *rt, char **splits, char c, int *x);

void				read_plane(t_rt *rt, char **splits, char c, int *x);

void				read_torus(t_rt *rt, char **splits, char c, int *x);

void				read_light(t_rt *rt, char **splits, char c, int *x);

void				error_exit(void);

#endif
