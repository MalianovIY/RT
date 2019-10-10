/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:32:46 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/05 22:32:46 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**t_int4	protect_overflow(t_int4 p)
**{
**	int	isn[3];
**
**	isn[0] = -1;
**	isn[2] = 0;
**	isn[1] = 0;
**	while (++isn[0] < 4)
**	{
**		isn[1] += p.v[isn[0]] - 255;
**		isn[2] = p.v[isn[0]] > 255 ? 1 : 0;
**	}
**	if (isn[2] > 0)
**	{
**		isn[1] = isn[1] / isn[2];
**		isn[0] = -1;
**		while (++isn[0] < 4)
**			if (p.v[isn[0]] > 255)
**				p.v[isn[0]] = 255;
**			else
**				p.v[isn[0]] = p.v[isn[0]] + isn[1] > 255 ?
**						255 : p.v[isn[0]] + isn[1];
**	}
**	return (p);
**}
*/

void	draw_point(t_rt *rt, int x, int y, t_int4 p)
{
	int		ind;

	if (y > rt->scr.v[1] - 1 || y < 0 || x > rt->scr.v[0] - 1 || x < 0)
		return ;
	ind = (rt->mlx.bit_per_pix / 8) * x + rt->mlx.size_len * y;
	rt->mlx.string[ind] = p.v[3] & 0xFF;
	rt->mlx.string[ind + 1] = p.v[2] & 0xFF;
	rt->mlx.string[ind + 2] = p.v[1] & 0xFF;
	rt->mlx.string[ind + 3] = p.v[0] & 0xFF;
}

void	init_mlx(t_rt *rt)
{
	if (rt->mlx.mlx != NULL)
		mlx_destroy_window(rt->mlx.mlx, rt->mlx.win);
	else
		rt->mlx.mlx = mlx_init();

	rt->mlx.win = mlx_new_window(rt->mlx.mlx, rt->scr.v[0], rt->scr.v[1], "RT");
	rt->mlx.img = mlx_new_image(rt->mlx.mlx, rt->scr.v[0], rt->scr.v[1]);
	rt->mlx.string = mlx_get_data_addr(rt->mlx.img,
			&(rt->mlx.bit_per_pix), &(rt->mlx.size_len), &(rt->mlx.endian));
	mlx_hook(rt->mlx.win, 2, 5, deal_key, rt);
	mlx_hook(rt->mlx.win, 17, 5, close_win, rt);
}

void	image_to_win(t_rt *rt)
{
	mlx_clear_window(rt->mlx.mlx, rt->mlx.win);
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win, rt->mlx.img, 0, 0);
	mlx_destroy_image(rt->mlx.mlx, rt->mlx.img);
}
