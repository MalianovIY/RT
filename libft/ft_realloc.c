/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:11:01 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/16 02:34:51 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_realloc(void **p, size_t n)
{
	unsigned char	*c;
	unsigned char	*d;
	unsigned char	*e;

	c = (unsigned char *)ft_memalloc(n);
	if (c == NULL)
		if (p != NULL)
			free(*p);
	if (c == NULL)
		return (p = NULL);
	d = c;
	if (p == NULL)
		return ((void *)c);
	if (*p != NULL)
	{
		e = (unsigned char *)*p;
		while (n && *e)
		{
			n--;
			*d++ = *e++;
		}
		free(*p);
		p = NULL;
	}
	return ((void *)c);
}
