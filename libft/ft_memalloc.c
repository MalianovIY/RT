/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 05:29:35 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/19 19:43:12 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t n)
{
	void	*a;

	a = (void *)malloc(n);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, n);
	return (a);
}
