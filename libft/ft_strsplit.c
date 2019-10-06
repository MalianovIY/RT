/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 01:01:40 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_strsplit(const char *c, char s)
{
	char	**o[2];
	char	*st;

	if (c == NULL)
		return (NULL);
	st = (char *)c;
	o[0] = (char **)malloc(sizeof(char *) * (ft_wrdcount(st, s) + 1));
	if (o[0] == NULL)
		return (NULL);
	o[1] = o[0];
	ft_bzero((void *)o[0], ft_wrdcount(st, s) + 1);
	o[0][ft_wrdcount(st, s)] = NULL;
	if (ft_wrdcount(st, s) == 0)
		return (o[1]);
	o[0][0] = st;
	while (*st++)
		if (*(st - 1) != s && (*st == s || *st == '\0'))
		{
			*o[0] = ft_strsub(*o[0], 0, st - *o[0]);
			if (*o[0]++ == NULL)
				return (ft_free2d((void ***)&(o[1])));
		}
		else if (*(st - 1) == s && *st != s && *st != '\0')
			*o[0] = st;
	return (o[1]);
}
