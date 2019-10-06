/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_vec_alp_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:12:10 by ahorker           #+#    #+#             */
/*   Updated: 2019/05/02 21:12:10 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libgm.h"

t_float4	gm_vec_alp_mult(t_float4 v1, double alpha)
{
	int			i;
	t_float4	v;

	v = v1;
	i = -1;
	while (++i < 3)
		v.v[i] *= alpha;
	return (v);
}
