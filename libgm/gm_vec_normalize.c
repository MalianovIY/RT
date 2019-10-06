/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_vec_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:12:10 by ahorker           #+#    #+#             */
/*   Updated: 2019/05/02 21:12:10 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libgm.h"

t_float4	gm_vec_normalize(t_float4 v1)
{
	float		len;
	int			i;
	t_float4	v;

	v = v1;
	len = gm_vec_len(v);
	if (len == 1 || len == 0)
		return (v);
	i = -1;
	while (++i < 3)
		v.v[i] /= len;
	return (v);
}
