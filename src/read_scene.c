/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 03:01:27 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/28 08:02:17 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	read_cone(t_rt *rt, char **splits, char c, int *x)
{
	int		i;
	t_cone	*t;

	i = -1;
	while (splits[++i])
		if (ft_strstr(splits[i], "cone:"))
		{
			t = &rt->obj.cones[(rt->obj.count_obj[3])++];
			*t = init_cone(
					gm_init_int(rt->obj.count_obj[3] - 1, (*x)++, 0, 0),
					gm_init_float(0, 0, 0, 0),
					gm_init_float(0, 0, 0, 0),
					gm_init_float(0, 0, 0, 0));
			while (splits[++i] != NULL)
				if (splits[i][0] == '\t')
					parse_cone(splits, i, t, c);
				else
					break ;
		}
}

void	read_sphere(t_rt *rt, char **splits, char c, int *x)
{
	int			i;
	t_sphere	*t;

	i = -1;
	while (splits[++i])
		if (ft_strstr(splits[i], "sphere:"))
		{
			t = &rt->obj.spheres[(rt->obj.count_obj[2])++];
			*t = init_sphere(
					gm_init_int(rt->obj.count_obj[2] - 1, (*x)++, 0, 0),
					gm_init_float(0, 0, 0, 0),
					gm_init_float(0, 0, 0, 0));
			while (splits[++i] != NULL)
				if (splits[i][0] == '\t')
					parse_sphere(splits, i, t, c);
				else
					break ;
		}
}

void	read_cylinder(t_rt *rt, char **splits, char c, int *x)
{
	int			i;
	t_cylinder	*t;

	i = -1;
	while (splits[++i])
		if (ft_strstr(splits[i], "cylinder:"))
		{
			t = &rt->obj.cylinders[(rt->obj.count_obj[1])++];
			*t = init_cylinder(gm_init_int(
					rt->obj.count_obj[1] - 1, (*x)++, 0, 0),
					gm_init_float(0, 0, 0, 0),
					gm_init_float(0, 0, 0, 0),
					gm_init_float(0, 0, 0, 0));
			while (splits[++i] != NULL)
				if (splits[i][0] == '\t')
					parse_cylinder(splits, i, t, c);
				else
					break ;
		}
}

void	read_plane(t_rt *rt, char **splits, char c, int *x)
{
	int		i;
	t_plane	*t;

	i = -1;
	while (splits[++i])
		if (ft_strstr(splits[i], "plane:"))
		{
			t = &rt->obj.planes[(rt->obj.count_obj[0])++];
			*t = init_plane(gm_init_int(rt->obj.count_obj[0] - 1, (*x)++, 0, 0),
					gm_init_float(0, 0, 0, 0), gm_init_float(0, 0, 0, 0),
					gm_init_float(0, 0, 0, 0));
			while (splits[++i] != NULL)
				if (splits[i][0] == '\t')
					parse_plane(splits, i, t, c);
				else
					break ;
		}
}

void	read_light(t_rt *rt, char **splits, char c, int *x)
{
	int		i;
	t_light	*t;

	i = -1;
	while (splits[++i])
		if (ft_strstr(splits[i], "light:"))
		{
			t = &rt->obj.lights[(rt->obj.count_obj[4])++];
			*t = init_light(gm_init_int(
					rt->obj.count_obj[4] - 1, (*x)++, 0, 0), ambient,
					gm_init_float(0, 0, 0, 0), 0);
			while (splits[++i] != NULL)
				if (splits[i][0] == '\t')
					parse_light(splits, i, t, c);
				else
					break ;
		}
}
