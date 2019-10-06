/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_mat_init_identity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:12:10 by ahorker           #+#    #+#             */
/*   Updated: 2019/05/02 21:12:10 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libgm.h"

t_mat4	gm_mat_init_identity(void)
{
	t_mat4	t;
	int		i;

	i = -1;
	while (++i < 4)
	{
		ft_bzero(&(t.v[i]), 4 * sizeof(float));
		t.v[i].v[i] = 1.0;
	}
	return (t);
}
