/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:47:50 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/18 22:03:08 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(const char *c, unsigned int s, size_t l)
{
	char	*p;
	char	*o;

	o = (char *)malloc((l + 1) * sizeof(char));
	if (o == NULL || c == NULL || s > ft_strlen(c))
		return (NULL);
	ft_bzero((void *)o, l + 1);
	p = o;
	c += s;
	while (l-- && *c)
		*p++ = (char)*c++;
	*p = '\0';
	return (o);
}
