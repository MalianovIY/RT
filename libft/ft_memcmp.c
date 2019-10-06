/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 01:28:24 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *a, const void *b, size_t n)
{
	unsigned char	*c;
	unsigned char	*d;
	int				o;

	if ((a == NULL && b == NULL) || n == 0)
		return (0);
	c = (unsigned char *)a;
	d = (unsigned char *)b;
	o = *c - *d;
	while (!o && n)
	{
		o = *c++ - *d++;
		n--;
	}
	return (o);
}
