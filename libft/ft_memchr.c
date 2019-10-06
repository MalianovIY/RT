/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 01:28:24 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *a, int c, size_t n)
{
	unsigned char	*b;
	unsigned char	uc;

	b = (unsigned char *)a;
	uc = (unsigned char)c;
	while (n--)
		if (*b++ == uc)
			return ((void*)(b - 1));
	return (NULL);
}
