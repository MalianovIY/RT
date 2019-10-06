/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 21:23:58 by ahorker           #+#    #+#             */
/*   Updated: 2018/12/19 20:56:12 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_atoi(const char *str)
{
	long int	num;
	int			s;

	num = 0;
	s = 1;
	if (str == NULL)
		return (0);
	while ((*str <= 13 && *str >= 9) || *str == ' ')
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0' && *str <= '9'))
		if (num >= 0 && num < 92233720368547758)
			num = (num * 10) + (*str++ - '0');
		else if (s == -1)
			return (0);
		else
			return (-1);
	return ((int)(num * s));
}
