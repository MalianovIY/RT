/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_vec_len_sqr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:12:10 by ahorker           #+#    #+#             */
/*   Updated: 2019/05/02 21:12:10 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libgm.h"
#include <stdio.h>

float	gm_vec_len_sqr(t_float4 v)
{
	float	len;
	int		i;

	len = 0;
	i = -1;
	while (++i < 3)
		len += v.v[i] * v.v[i];
	return (len);
}
