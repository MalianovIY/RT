/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 04:04:24 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/16 02:03:30 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t n)
{
	char	*a;

	if (n + 1 == 0)
		return (NULL);
	a = (char *)malloc(n + 1);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, n + 1);
	return (a);
}
