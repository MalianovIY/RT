/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:12:10 by ahorker           #+#    #+#             */
/*   Updated: 2019/05/02 21:12:10 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGM_H
# define LIBGM_H

# include "../../libft/includes/libft.h"
# include <math.h>

typedef struct		s_float4
{
	float			v[4];
}					t_float4;

typedef struct		s_int4
{
	int				v[4];
}					t_int4;

typedef struct		s_mat4
{
	t_float4		v[4];
}					t_mat4;

float				gm_vec_len(t_float4 v);

float				gm_vec_len_sqr(t_float4 v);

float				gm_vec_dot(t_float4 v, t_float4 v1);

t_float4			gm_vec_normalize(t_float4 v);

t_float4			gm_vec_subtract(t_float4 v1, t_float4 v2);

t_float4			gm_vec_minus(t_float4 v1);

t_float4			gm_vec_add(t_float4 v1, t_float4 v2);

t_float4			gm_vec_mult(t_float4 v, t_float4 v2);

float				gm_vec_cos(t_float4 v, t_float4 v1);

t_float4			gm_init_float(float x, float y, float z, float w);

t_int4				gm_init_int(int x, int y, int z, int w);

t_mat4				gm_mat_mult(t_mat4 t1, t_mat4 t2);

t_float4			gm_mat_pnt_mult(t_float4 v, t_mat4 t);

t_float4			gm_vec_mat_mult(t_float4 v1, t_mat4 t);

t_float4			gm_vec_alp_mult(t_float4 v1, double alpha);

t_mat4				gm_mat_init_identity(void);

t_mat4				gm_mat_create(t_float4 v_1, t_float4 v_2,
									t_float4 v_3, t_float4 v_4);

t_mat4				gm_mat_transpose(t_mat4 t);

t_mat4				gm_mat_inversion(t_mat4 t);

t_float4			gm_vec_reflect(t_float4 vector, t_float4 normal);

t_float4			gm_vec_vec_rotate(t_float4 vec1, t_float4 vec2, float ang);
t_float4			gm_vec_ortog(t_float4 v_base, t_float4 v_ort);

#endif
