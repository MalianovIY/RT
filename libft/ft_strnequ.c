/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:33:58 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strnequ(const char *c1, const char *c2, size_t n)
{
	if (c1 == NULL || c2 == NULL || n == 0)
		return (1);
	while (*c1 && *c2 && n--)
		if (*c1++ != *c2++)
			return (0);
	if ((*c1 && !(*c2)) || (!(*c1) && *c2))
		return (0);
	return (1);
}
