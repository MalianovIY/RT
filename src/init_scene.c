/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_prog.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 23:00:20 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/05 23:00:20 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_float4	split_float4(char *s, char c)
{
	char		**splits;
	t_float4	vec;
	int			j;

	j = -1;
	splits = ft_strsplit(s, c);
	while (splits[++j])
		vec.v[j] = (float)ft_atof(splits[j]);
	ft_free2d((void ***)&splits);
	return (vec);
}

t_int4		split_int4(char *s, char c)
{
	char	**splits;
	t_int4	vec;
	int		j;

	j = -1;
	ft_bzero(&(vec.v[0]), 4 * sizeof(int));
	splits = ft_strsplit(s, c);
	while (splits[++j])
		vec.v[j] = (float)ft_atoi(splits[j]);
	ft_free2d((void ***)&splits);
	return (vec);
}

void		parse_camera(t_rt *rt, char **splits, int i, char c)
{
	if ((ft_strstr(splits[i], "center:")))
		rt->o = split_float4(&(splits[i][8]), c);
	else if ((ft_strstr(splits[i], "screen:")))
	{
		rt->scr = split_int4(&(splits[i][8]), c);
		if (rt->scr.v[0] < 32 || rt->scr.v[1] < 18)
			rt->scr = gm_init_int(32, 18, 16, 9);
		rt->scr = gm_init_int(rt->scr.v[0], rt->scr.v[1],
				rt->scr.v[0] / 2, rt->scr.v[1] / 2);
	}
}

void		read_camera(t_rt *rt, char **splits, char c)
{
	int		i;

	if (rt->mlx.mlx == NULL)
	{
		rt->o = gm_init_float(0, 1, 0, 0);
		rt->t = gm_mat_init_identity();
		rt->scr = gm_init_int(320, 180, 160, 90);
		rt->cnv = gm_init_float(0.001f * 16.f / 9.f, 0.001f, 0.001, 0);
	}
	i = -1;
	while (splits[++i])
		if (ft_strstr(splits[i], "camera:"))
		{
			while (splits[++i] != NULL)
				if (splits[i][0] == '\t')
					parse_camera(rt, splits, i, c);
				else
					break;
		}
}

void		init_scene(t_rt *rt, char *file)
{
	int		i[2];
	char	**splits;
	char	buf[100000];

	ft_bzero(rt->obj.count_obj, 5 * sizeof(int));
	if ((i[1] = open(file, O_RDONLY)) < 3)
		exit(0);
	i[0] = read(i[1], buf, 99999);
	if (i[0] < 7)
		exit(0);
	buf[i[0]] = 0;
	close(i[1]);
	i[0] = 0;
	i[1] = 0;
	splits = ft_strsplit(buf, '\n');
	if (splits == NULL)
		exit((int)ft_free2d((void ***)&splits));
	read_camera(rt, splits, ',');
	read_sphere(rt, splits, ',', &i[0]);
	read_cone(rt, splits, ',', &i[0]);
	read_cylinder(rt, splits, ',', &i[0]);
	read_plane(rt, splits, ',', &i[0]);
	read_light(rt, splits, ',', &i[0]);
	ft_free2d((void ***)&splits);
	init_mlx(rt);
}
