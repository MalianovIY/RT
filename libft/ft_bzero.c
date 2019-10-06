/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 01:28:15 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/16 02:02:28 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;

	if (s != NULL)
	{
		a = (unsigned char *)s;
		while (n--)
			*a++ = 0;
	}
}
