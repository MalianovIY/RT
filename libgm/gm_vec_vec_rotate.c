/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_vec_vec_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:40:50 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/05 22:40:50 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libgm.h"

t_float4		gm_vec_vec_rotate(t_float4 ax_1, t_float4 ax_2, float angle)
{
	double tmp[6];

	tmp[3] = cos(angle);
	tmp[4] = 1 - tmp[3];
	tmp[5] = sin(angle);
	tmp[0] = ax_2.v[0] * (tmp[3] + tmp[4] * ax_1.v[0] * ax_1.v[0])
			+ ax_2.v[1] * (tmp[4] * ax_1.v[0] * ax_1.v[1] - tmp[5] * ax_1.v[2])
			+ ax_2.v[2] * (tmp[4] * ax_1.v[0] * ax_1.v[2] + tmp[5] * ax_1.v[1]);
	tmp[1] = ax_2.v[0] * (tmp[4] * ax_1.v[0] * ax_1.v[1] + tmp[5] * ax_1.v[2])
			+ ax_2.v[1] * (tmp[3] + tmp[4] * ax_1.v[1] * ax_1.v[1])
			+ ax_2.v[2] * (tmp[4] * ax_1.v[1] * ax_1.v[2] - tmp[5] * ax_1.v[0]);
	tmp[2] = ax_2.v[0] * (tmp[4] * ax_1.v[0] * ax_1.v[2] - tmp[5] * ax_1.v[1])
			+ ax_2.v[1] * (tmp[4] * ax_1.v[1] * ax_1.v[2] + tmp[5] * ax_1.v[0])
			+ ax_2.v[2] * (tmp[3] + tmp[4] * ax_1.v[2] * ax_1.v[2]);
	ax_2.v[0] = tmp[0];
	ax_2.v[1] = tmp[1];
	ax_2.v[2] = tmp[2];
	return (ax_2);
}
