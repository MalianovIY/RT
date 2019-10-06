/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 01:28:24 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)d;
	b = (unsigned char *)s;
	if (s > d)
		while (n--)
			*a++ = *b++;
	else if (a == NULL && b == NULL)
	{
		return (NULL);
	}
	else
	{
		a += n - 1;
		b += n - 1;
		while (n--)
			*a-- = *b--;
	}
	return (d);
}
