/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 01:28:24 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t l)
{
	size_t		l1;

	l1 = 0;
	while (d[l1] && l1 < l)
		l1++;
	if (l1 < l)
	{
		while (l1 < l && *s)
			d[l1++] = *s++;
		if (l1 < l)
		{
			d[l1] = '\0';
			return (l1);
		}
		else
		{
			d[l1 - 1] = '\0';
			while (*s++)
				l1++;
			return (l1);
		}
	}
	while (*s++)
		l1++;
	return (l1);
}
