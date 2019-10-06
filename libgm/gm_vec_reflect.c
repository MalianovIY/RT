/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_vec_reflect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:30:53 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/05 22:30:53 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libgm.h"

t_float4	gm_vec_reflect(t_float4 v, t_float4 n)
{
	return (gm_vec_subtract(gm_vec_alp_mult(n, 2 * gm_vec_dot(n, v)), v));
}
