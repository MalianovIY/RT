/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 01:28:24 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/26 22:51:04 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *d, const char *s, size_t l)
{
	unsigned char	*d1;
	unsigned char	*s1;

	s1 = (unsigned char*)s;
	d1 = (unsigned char*)d;
	if (!d || !s)
		return (NULL);
	while (*s1 && l)
	{
		*d1++ = *s1++;
		l--;
	}
	while (l)
	{
		l--;
		*d1++ = '\0';
	}
	return (d);
}
