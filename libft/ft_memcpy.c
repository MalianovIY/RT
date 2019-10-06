/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 01:28:24 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)d;
	b = (unsigned char *)s;
	if (a == NULL && b == NULL)
		return (NULL);
	while (n--)
		*a++ = *b++;
	return (d);
}
