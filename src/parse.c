/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 02:54:50 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/10 02:54:50 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	parse_cone(char **splits, int i, t_cone *t, char c)
{
	if ((ft_strstr(splits[i], "center:")))
		t->center = split_float4(&(splits[i][8]), c);
	else if ((ft_strstr(splits[i], "axis:")))
		t->norm = split_float4(&(splits[i][6]), c);
	else if ((ft_strstr(splits[i], "angle:")))
		t->data.v[1] = fabs(tan((float)ft_atof(&splits[i][7]) * M_PI / 180));
	else if ((ft_strstr(splits[i], "reflection:")))
		t->data.v[0] = (float)ft_atof(&splits[i][12]);
	else if ((ft_strstr(splits[i], "specular:")))
		t->id.v[3] = ft_atoi(&splits[i][10]);
	else if ((ft_strstr(splits[i], "color:")))
		t->id.v[2] = splits[i][8] == '0' && (splits[i][9] == 'x'
				|| splits[i][9] == 'X') ? ft_atoi_base(&splits[i][10], 16)
										: ft_atoi_base(&splits[i][7], 10);
	else if ((ft_strstr(splits[i], "data:")))
		t->data = split_float4(&(splits[i][6]), c);
}

void	parse_sphere(char **splits, int i, t_sphere *t, char c)
{
	if ((ft_strstr(splits[i], "center:")))
		t->center = split_float4(&(splits[i][8]), c);
	else if ((ft_strstr(splits[i], "radius:")))
		t->data.v[1] = (float)ft_atof(&splits[i][8]);
	else if ((ft_strstr(splits[i], "reflection:")))
		t->data.v[0] = (float)ft_atof(&splits[i][12]);
	else if ((ft_strstr(splits[i], "specular:")))
		t->id.v[3] = ft_atoi(&splits[i][10]);
	else if ((ft_strstr(splits[i], "color:")))
		t->id.v[2] = splits[i][8] == '0' && (splits[i][9] == 'x'
				|| splits[i][9] == 'X') ? ft_atoi_base(&splits[i][10], 16)
										: ft_atoi_base(&splits[i][7], 10);
	else if ((ft_strstr(splits[i], "data:")))
		t->data = split_float4(&(splits[i][6]), c);
}

void	parse_cylinder(char **splits, int i, t_cylinder *t, char c)
{
	if ((ft_strstr(splits[i], "center:")))
		t->center = split_float4(&(splits[i][8]), c);
	else if ((ft_strstr(splits[i], "axis:")))
		t->norm = split_float4(&(splits[i][6]), c);
	else if ((ft_strstr(splits[i], "radius:")))
		t->data.v[1] = (float)ft_atof(&splits[i][8]);
	else if ((ft_strstr(splits[i], "reflection:")))
		t->data.v[0] = (float)ft_atof(&splits[i][12]);
	else if ((ft_strstr(splits[i], "specular:")))
		t->id.v[3] = ft_atoi(&splits[i][10]);
	else if ((ft_strstr(splits[i], "color:")))
		t->id.v[2] = splits[i][8] == '0' && (splits[i][9] == 'x'
				|| splits[i][9] == 'X') ? ft_atoi_base(&splits[i][10], 16)
										: ft_atoi_base(&splits[i][7], 10);
	else if ((ft_strstr(splits[i], "data:")))
		t->data = split_float4(&(splits[i][6]), c);
}

void	parse_plane(char **splits, int i, t_plane *t, char c)
{
	if ((ft_strstr(splits[i], "center:")))
		t->point = split_float4(&(splits[i][8]), c);
	else if ((ft_strstr(splits[i], "norm:")))
		t->norm = split_float4(&(splits[i][6]), c);
	else if ((ft_strstr(splits[i], "reflection:")))
		t->data.v[0] = (float)ft_atof(&splits[i][12]);
	else if ((ft_strstr(splits[i], "specular:")))
		t->id.v[3] = ft_atoi(&splits[i][10]);
	else if ((ft_strstr(splits[i], "color:")))
		t->id.v[2] = splits[i][8] == '0' && (splits[i][9] == 'x'
				|| splits[i][9] == 'X') ? ft_atoi_base(&splits[i][10], 16)
										: ft_atoi_base(&splits[i][7], 10);
	else if ((ft_strstr(splits[i], "data:")))
		t->data = split_float4(&(splits[i][6]), c);
}

void	parse_light(char **splits, int i, t_light *t, char c)
{
	if ((ft_strstr(splits[i], "type:")))
	{
		if (ft_strstr(&(splits[i][7]), "point") == 0)
			t->type = point;
		else
			t->type = (ft_strstr(&(splits[i][7]), "dir") == 0) ? dir : ambient;
	}
	else if ((ft_strstr(splits[i], "point:"))
			|| (ft_strstr(splits[i], "direct:")))
		t->pos = split_float4(&(splits[i][8]), c);
	else if ((ft_strstr(splits[i], "intensive:")))
		t->intn = (float)ft_atof(&splits[i][11]);
}
