/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 01:28:24 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/26 22:34:47 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strccpy(char *d, const char *s, char c)
{
	char	*d1;

	d1 = d;
	if (!d || !s)
		return (NULL);
	while (*s && *s != c)
		*d1++ = *s++;
	*d1 = '\0';
	return (d);
}
