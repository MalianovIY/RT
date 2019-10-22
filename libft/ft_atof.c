/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 01:48:02 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/10 01:48:02 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

double	ft_atof(char *str)
{
	int			i;
	int			x;
	double		sign;
	double		res;

	i = 0;
	x = 0;
	res = 0;
	while (str[i] == ' ')
		i++;
	sign = (str[i] == '-' ? -1 : 1);
	i += ((str[i] == '-' || str[i] == '+') ? 1 : 0);
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != '.' && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	i += ((str[i] == '.') ? 1 : 0);
	while (str[i + x] && (str[i + x] >= '0' && str[i + x] <= '9'))
		res = res * 10 + (str[i + x++] - '0');
	while (x-- > 0)
		res /= 10;
	return (res * sign);
}
