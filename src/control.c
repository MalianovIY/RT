/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:38:03 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/28 09:16:32 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		close_win(void *param)
{
	(void)param;
	exit(0);
}

void	rotation_pos(t_rt *rt, int key, float angle)
{
	if (key == 12)
	{
		rt->t.v[0] = gm_vec_vec_rotate(rt->t.v[2], rt->t.v[0], angle);
		rt->t.v[1] = gm_vec_vec_rotate(rt->t.v[2], rt->t.v[1], angle);
	}
	else if (key == 123)
	{
		rt->t.v[0] = gm_vec_vec_rotate(rt->t.v[1], rt->t.v[0], angle);
		rt->t.v[2] = gm_vec_vec_rotate(rt->t.v[1], rt->t.v[2], angle);
	}
	else if (key == 125)
	{
		rt->t.v[2] = gm_vec_vec_rotate(rt->t.v[0], rt->t.v[2], angle);
		rt->t.v[1] = gm_vec_vec_rotate(rt->t.v[0], rt->t.v[1], angle);
	}
}

void	rotation_neg(t_rt *rt, int key, float angle)
{
	if (key == 14)
	{
		rt->t.v[0] = gm_vec_vec_rotate(rt->t.v[2], rt->t.v[0], angle);
		rt->t.v[1] = gm_vec_vec_rotate(rt->t.v[2], rt->t.v[1], angle);
	}
	else if (key == 124)
	{
		rt->t.v[0] = gm_vec_vec_rotate(rt->t.v[1], rt->t.v[0], angle);
		rt->t.v[2] = gm_vec_vec_rotate(rt->t.v[1], rt->t.v[2], angle);
	}
	else if (key == 126)
	{
		rt->t.v[2] = gm_vec_vec_rotate(rt->t.v[0], rt->t.v[2], angle);
		rt->t.v[1] = gm_vec_vec_rotate(rt->t.v[0], rt->t.v[1], angle);
	}
}

void	move_control(t_rt *rt, int key)
{
	if (key == 53)
		exit(0);
	else if (key == 36)
		init_scene(rt, rt->filename);
	else if (key == 13)
		rt->o.v[2] += 1;
	else if (key == 1)
		rt->o.v[2] -= 1;
	else if (key == 2)
		rt->o.v[0] += 1;
	else if (key == 0)
		rt->o.v[0] -= 1;
	else if (key == 116)
		rt->o.v[1] += 1;
	else if (key == 121)
		rt->o.v[1] -= 1;
}

int		deal_key(int key, void *param)
{
	t_rt	*rt;

	rt = (t_rt *)param;
	if (key == 53 || key == 13 || key == 1 || key == 2 || key == 0
			|| key == 116 || key == 121 || key == 36)
		move_control(rt, key);
	else if (key == 12 || key == 123 || key == 125)
		rotation_pos(rt, key, M_PI / 36);
	else if (key == 14 || key == 124 || key == 126)
		rotation_neg(rt, key, -M_PI / 36);
	rt->mlx.img = mlx_new_image(rt->mlx.mlx, rt->scr.v[0], rt->scr.v[1]);
	rt->mlx.string = mlx_get_data_addr(rt->mlx.img,
			&(rt->mlx.bit_per_pix), &(rt->mlx.size_len), &(rt->mlx.endian));
	calc(rt);
	return (0);
}
