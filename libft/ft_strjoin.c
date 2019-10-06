/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 04:13:54 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/19 22:12:09 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(const char *c1, const char *c2)
{
	char	*o[2];
	int		l[2];

	if (c1 == NULL || c2 == NULL)
		return (NULL);
	l[0] = 0;
	l[1] = 0;
	while (c1[l[0]])
		l[0]++;
	while (c2[l[1]])
		l[1]++;
	o[0] = (char *)ft_memalloc((l[0] + l[1] + 1) * sizeof(char));
	if (o[0] == NULL)
		return (NULL);
	o[1] = o[0];
	while (*c1)
		*o[1]++ = *c1++;
	while (*c2)
		*o[1]++ = *c2++;
	*o[1] = '\0';
	return (o[0]);
}
