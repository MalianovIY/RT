/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 02:21:37 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_wrdcount(char *c, char s)
{
	int	n;

	n = 0;
	if (c == NULL)
		return (-1);
	if (ft_strchr(c, s) == 0)
		return (0);
	while (*c)
		if (*c++ != s && (*c == s || *c == '\0'))
			n++;
	return (n);
}
