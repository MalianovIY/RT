/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 01:28:24 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)d;
	b = (unsigned char *)s;
	while (n--)
	{
		*a++ = *b++;
		if (*(a - 1) == (unsigned char)c)
			return ((char *)a);
	}
	return (NULL);
}
