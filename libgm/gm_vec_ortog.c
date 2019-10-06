/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_vec_ortog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 01:55:33 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/06 01:55:33 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libgm.h"

t_float4	gm_vec_ortog(t_float4 v1, t_float4 v2)
{
	return(gm_vec_subtract(v1, gm_vec_alp_mult(v2, gm_vec_dot(v1, v2)
													/ gm_vec_len_sqr(v2))));
}