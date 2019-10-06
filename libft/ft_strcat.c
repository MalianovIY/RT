/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 01:28:24 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/16 01:38:20 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *d, const char *s)
{
	char	*d1;

	if (!d || !s)
		return (NULL);
	d1 = d;
	while (*d1)
		d1++;
	while (*s)
		*d1++ = *s++;
	*d1 = '\0';
	return (d);
}
